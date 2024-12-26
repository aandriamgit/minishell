/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_no_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:23:18 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:30:31 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_t_pipe_a.h"

static void	extra(t_pipe_a *pipe_a, t_vars *vars)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0 && vars->env_cpy)
		execve(pipe_a->cmd->cmd, pipe_a->cmd->args, ft_gen_env(vars->env));
	else if (pid < 0)
		ft_perror_soft("fork error", "no_pipe", vars, 1);
	else
		vars->exit_code_int = handle_child_exit_no_pipe(pid, vars);
}

static void	relative_path(t_pipe_a *pipe_a, t_vars *vars)
{
	char		*mini_cmd;
	char		*lol;
	struct stat	file_stat;

	mini_cmd = pipe_a->cmd->cmd;
	if (!mini_cmd[1])
		ft_perror_soft(mini_cmd, "filename argument required\n", vars, 2);
	else if (mini_cmd[1] == '/' || mini_cmd[1] == '.')
	{
		if (mini_cmd[1] == '/')
			lol = ft_substr_a(mini_cmd, 2, ft_strlen_a(mini_cmd));
		else
			lol = ft_strdup_a(mini_cmd);
		if (stat(lol, &file_stat) == -1)
			ft_perror_redir(mini_cmd, vars, ENOENT, 1);
		else if (access(lol, X_OK) == -1)
			ft_perror_redir(mini_cmd, vars, EACCES, 1);
		else if (S_ISDIR(file_stat.st_mode))
			ft_perror_redir(mini_cmd, vars, EISDIR, 1);
		else
			extra(pipe_a, vars);
		free(lol);
	}
	else
		ft_perror_soft(mini_cmd, "command not found\n", vars, 127);
}

static void	absolute_path(t_pipe_a *pipe_a, t_vars *vars)
{
	char		*lol;
	struct stat	file_stat;

	lol = pipe_a->cmd->cmd;
	if (stat(lol, &file_stat) == -1)
		ft_perror_redir(lol, vars, ENOENT, 1);
	else if (access(lol, X_OK) == -1)
		ft_perror_redir(lol, vars, EACCES, 1);
	else if (S_ISDIR(file_stat.st_mode))
		ft_perror_redir(lol, vars, EISDIR, 1);
	else
		extra(pipe_a, vars);
}

void	path_no_pipe(t_pipe_a *pipe_a, t_vars *vars)
{
	if (pipe_a->cmd->cmd[0] == '.')
		relative_path(pipe_a, vars);
	else
		absolute_path(pipe_a, vars);
}
