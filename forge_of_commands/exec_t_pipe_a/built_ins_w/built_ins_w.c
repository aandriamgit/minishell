/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:18:13 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/16 12:10:49 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

void	built_ins_w(t_command_a *cmd, t_vars *vars)
{
	if (ft_strncmp_a(cmd->args[0], "echo") == 0)
		ft_echo_w(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "cd") == 0)
		ft_cd_w(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "pwd") == 0)
		ft_pwd_w(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "unset") == 0)
		ft_unset_w(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "env") == 0)
		ft_env_w(cmd, vars);
	else if (ft_strncmp_a(cmd->args[0], "export") == 0)
		ft_export_w(cmd, vars);
}
