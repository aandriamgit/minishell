/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:09:45 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/28 09:54:46 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "exec_t_pipe_a.h"
#include <unistd.h>

static void	w_pipe(t_pipe_a *pipe_a, t_vars *vars)
{
	int	status;

	gen_pid_a(pipe_a, vars);
	while (pipe_a)
	{
		if (waitpid(pipe_a->pid, &status, 0) == -1)
			ft_perror_exit("waitpid", "w_pipe\n", vars, 1);
		if (WIFSIGNALED(status))
			vars->exit_code_int = 128 + WTERMSIG(status);
		else if (WIFEXITED(status))
			vars->exit_code_int = WEXITSTATUS(status);
		pipe_a = pipe_a->next;
	}
}

int	handle_child_exit_no_pipe(pid_t child_pid, t_vars *vars)
{
	int	status;

	if (waitpid(child_pid, &status, 0) == -1)
	{
		ft_perror_soft("waitpid", "handle_child_exit_no_pipe", vars, 1);
		return (-1);
	}
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (-1);
}

static void	extra(t_pipe_a *pipe_a, t_vars *vars)
{
	pid_t	pid;
	int		flag;

	flag = 0;
	handle_redir(pipe_a->cmd->redir, vars, &flag);
	if (flag)
	{
		if (pipe_a->cmd->cmd[0] == '.' || pipe_a->cmd->cmd[0] == '/')
			path_no_pipe(pipe_a, vars);
		else if (cmd_check(pipe_a->cmd->cmd, vars))
		{
			pid = fork();
			if (pid == 0)
			{
				signal(SIGQUIT, SIG_DFL);
				signal(SIGINT, SIG_DFL);
				ft_execve_path(pipe_a, pipe_a->cmd->cmd, pipe_a->cmd->args,
					vars);
			}
			else if (pid < 0)
				ft_perror_soft("fork error", "no_pipe", vars, 1);
			else
				vars->exit_code_int = handle_child_exit_no_pipe(pid, vars);
		}
	}
}

static void	no_pipe(t_pipe_a *pipe_a, t_vars *vars)
{
	int	in;
	int	out;

	if (is_built_ins(pipe_a->cmd))
		built_ins_n(pipe_a->cmd, vars);
	else
	{
		in = dup(STDIN_FILENO);
		out = dup(STDOUT_FILENO);
		extra(pipe_a, vars);
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		close(in);
		close(out);
	}
}

void	exec_t_pipe_a(t_pipe_a *pipe_a, t_vars *vars)
{
	if (pipe_a)
	{
		vars->t_pipe_a = pipe_a;
		if (pipe_a->next)
			w_pipe(pipe_a, vars);
		else
		{
			no_pipe(pipe_a, vars);
		}
	}
}
