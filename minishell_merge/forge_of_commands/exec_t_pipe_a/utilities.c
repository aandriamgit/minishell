/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:25:25 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 08:51:23 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_built_ins_n/exec_built_ins_n.h"
#include "exec_built_ins_w/exec_built_ins_w.h"
#include "exec_t_pipe_a.h"

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

void	exec_built_ins_w(t_command_a *cmd, t_vars *vars)
{
	if (ft_strncmp_a(cmd->args[0], "echo") == 0)
		ft_echo_w(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "cd") == 0)
		ft_cd_w(cmd, vars);
}

void	exec_built_ins_n(t_command_a *cmd, t_vars *vars)
{
	if (ft_strncmp_a(cmd->args[0], "echo") == 0)
		ft_echo_n(cmd);
	else if (ft_strncmp_a(cmd->args[0], "cd") == 0)
		ft_cd_n(cmd, vars);
}
