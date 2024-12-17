/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_pid_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:55:03 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/17 13:23:53 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_ins_w/built_ins_w.h"
#include "../exec_t_pipe_a.h"

static void	handle_cmd(t_pipe_a *pipe_a, int input_fd, int output_fd,
		t_vars *vars)
{
	int	flag;

	flag = 0;
	if (pipe_a->prev && input_fd != 0)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (pipe_a->next && output_fd != 1)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
	handle_redir(pipe_a->cmd->redir, vars, &flag);
	if (flag)
	{
		if (is_built_ins(pipe_a->cmd))
			built_ins_w(pipe_a->cmd, vars);
		else if (pipe_a->cmd->cmd[0] == '.' || pipe_a->cmd->cmd[0] == '/')
			path_w_pipe(pipe_a, vars);
		else
			ft_execve_path(pipe_a, pipe_a->cmd->cmd, pipe_a->cmd->args, vars);
	}
	else
		ft_perror_exit(NULL, NULL, vars, 1);
}

void	gen_pid_a(t_pipe_a *pipe_a, t_vars *vars)
{
	int	pipe_fd[2];
	int	input_fd;

	input_fd = 0;
	while (pipe_a)
	{
		if (pipe_a->prev || pipe_a->next)
			if (pipe(pipe_fd) == -1)
				ft_perror_exit("pipe", "gen_pid_a\n", vars, 1);
		pipe_a->pid = fork();
		if (pipe_a->pid == 0)
			handle_cmd(pipe_a, input_fd, pipe_fd[1], vars);
		else if (pipe_a->pid < 0)
			ft_perror_exit("fork", "gen_pid_a\n", vars, 1);
		if (pipe_a->next)
			close(pipe_fd[1]);
		if (input_fd != 0)
			close(input_fd);
		input_fd = pipe_fd[0];
		pipe_a = pipe_a->next;
		vars->err_nbr++;
	}
}
