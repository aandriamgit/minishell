/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:01:36 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/18 09:31:16 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_n.h"

void	built_ins_n(t_command_a *cmd, t_vars *vars)
{
	if (ft_strncmp_a(cmd->args[0], "echo") == 0)
		ft_echo_n(cmd, vars);
	if (ft_strncmp_a(cmd->args[0], "cd") == 0)
		ft_cd_n(cmd, vars);
	if (ft_strncmp_a(cmd->args[0], "pwd") == 0)
		ft_pwd_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "unset") == 0)
		ft_unset_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "env") == 0)
		ft_env_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "export") == 0)
		ft_export_n(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "exit") == 0)
		ft_exit_n(cmd, vars);
}
