/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:01:36 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 13:27:26 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_n.h"

int	is_built_ins(t_command_a *cmd)
{
	if (cmd->args[0] == NULL)
		return (0);
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
	else if (ft_strncmp_a(cmd->args[0], "custom_perror") == 0)
		return (1);
	else if (ft_strncmp_a(cmd->args[0], "custom_prompt") == 0)
		return (1);
	return (0);
}

void	built_ins_n(t_command_a *cmd, t_vars *vars)
{
	if (ft_strncmp_a(cmd->args[0], "echo") == 0)
		ft_echo_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "cd") == 0)
		ft_cd_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "pwd") == 0)
		ft_pwd_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "unset") == 0)
		ft_unset_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "env") == 0)
		ft_env_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "export") == 0)
		ft_export_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "exit") == 0)
		ft_exit_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "custom_perror") == 0)
		custom_perror(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "custom_prompt") == 0)
		built_custom_prompt(cmd, vars);
}
