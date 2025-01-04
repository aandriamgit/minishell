/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_w_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:22:27 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/04 16:48:18 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_t_pipe_a.h"

static void	relative_path(t_pipe_a *pipe_a, t_vars *vars)
{
	char		*lol;
	struct stat	file_stat;

	if (!pipe_a->cmd->cmd[1])
		ft_perror_exit(pipe_a->cmd->cmd, "filename argument required\n", vars,
			2);
	else if (pipe_a->cmd->cmd[1] == '/' || pipe_a->cmd->cmd[1] == '.')
	{
		if (pipe_a->cmd->cmd[1] == '/')
			lol = ft_substr_a(pipe_a->cmd->cmd, 2,
					ft_strlen_a(pipe_a->cmd->cmd));
		else
			lol = ft_strdup_a(pipe_a->cmd->cmd);
		if (stat(lol, &file_stat) == -1)
			ft_perror_exit(lol, "no such file or directory\n", vars, 127);
		else if (access(lol, X_OK) == -1)
			ft_perror_exit(lol, "access denied\n", vars, 126);
		else if (S_ISDIR(file_stat.st_mode))
			ft_perror_exit(lol, "is a directory\n", vars, 126);
		else
			execve(pipe_a->cmd->cmd, pipe_a->cmd->args, ft_gen_env(vars->env));
	}
	else
		ft_perror_exit(pipe_a->cmd->cmd, "command not found\n", vars, 127);
}

static void	absolute_path(t_pipe_a *pipe_a, t_vars *vars)
{
	char		*lol;
	struct stat	file_stat;

	lol = pipe_a->cmd->cmd;
	if (stat(lol, &file_stat) == -1)
		ft_perror_exit(lol, "no such file or directory\n", vars, 127);
	else if (access(lol, X_OK) == -1)
		ft_perror_exit(lol, "access denied\n", vars, 126);
	else if (S_ISDIR(file_stat.st_mode))
		ft_perror_exit(lol, "is a directory\n", vars, 126);
	else
		execve(pipe_a->cmd->cmd, pipe_a->cmd->args, ft_gen_env(vars->env));
}

void	path_w_pipe(t_pipe_a *pipe_a, t_vars *vars)
{
	if (pipe_a->cmd->cmd[0] == '.')
		relative_path(pipe_a, vars);
	else
		absolute_path(pipe_a, vars);
}
