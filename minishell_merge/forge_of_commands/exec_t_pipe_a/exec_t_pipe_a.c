/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:11:52 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/15 12:07:24 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_t_pipe_a.h"

static void	w_pipe(t_pipe_a *pipe_a, t_vars *vars)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		input_fd;

	input_fd = 0;
	while (pipe_a)
	{
		if (pipe_a->prev || pipe_a->next)
			if (pipe(pipe_fd) == -1)
				ft_perror_row("pipe error", NULL, vars);
		pid = fork();
		if (pid == 0)
			handle_cmd(*pipe_a, input_fd, pipe_fd[1], vars);
		else if (pid < 0)
			ft_perror_row("fork error", NULL, vars);
		if (pipe_a->next)
			close(pipe_fd[1]);
		if (input_fd != 0)
			close(input_fd);
		input_fd = pipe_fd[0];
		pipe_a = pipe_a->next;
	}
	while (wait(NULL) > 0)
		;
}

static void	no_pipe(t_pipe_a *pipe_a, t_vars *vars)
{
	pid_t	pid;

	if (is_built_ins(pipe_a->cmd))
		exec_built_ins_n(pipe_a->cmd, vars);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			handle_redir(pipe_a->cmd->redir, vars);
			ft_execve_path(pipe_a->cmd->cmd, pipe_a->cmd->args, vars);
		}
		else if (pid < 0)
			ft_perror_row("error no_pipe fork\n", NULL, vars);
		else
			wait(NULL);
	}
}

void	exec_t_pipe_a(t_pipe_a *pipe_a, t_vars *vars)
{
	if (pipe_a)
	{
		if (pipe_a->next)
			w_pipe(pipe_a, vars);
		else
			no_pipe(pipe_a, vars);
	}
}
