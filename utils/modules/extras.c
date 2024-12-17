/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:52:41 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/04 14:42:07 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*get_file_dir(char *file)
{
	char	*res;
	char	*lol;

	lol = ft_strrchr_a(file, '/');
	if (!lol)
		return (NULL);
	lol++;
	res = ft_substr_a(file, 0, (ft_strlen_a(file) - ft_strlen_a(lol)));
	return (res);
}

int	is_built_ins(t_command_a *cmd)
{
	if (ft_strncmp_a(cmd->args[0], "echo") == 0)
		return (1);
	else if (ft_strncmp_a(cmd->args[0], "cd") == 0)
		return (1);
	else if (ft_strncmp_a(cmd->args[0], "pwd") == 0)
		return (1);
	else if (ft_strncmp_a(cmd->args[0], "export") == 0)
		return (1);
	else if (ft_strncmp_a(cmd->args[0], "unset") == 0)
		return (1);
	else if (ft_strncmp_a(cmd->args[0], "env") == 0)
		return (1);
	else if (ft_strncmp_a(cmd->args[0], "exit") == 0)
		return (1);
	return (0);
}

int	cmd_check(char *cmd, t_vars *vars)
{
	char	*path;
	char	*mini_cmd;

	mini_cmd = ft_strjoin_a("/", cmd);
	path = test_path(getenv("PATH"), mini_cmd);
	if (path)
	{
		free(path);
		return (1);
	}
	ft_perror_soft(cmd, "command not found\n", vars, 127);
	return (0);
}
