/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_perror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:58:31 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 13:27:01 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_n.h"

void	built_custom_prompt(t_command_a *cmd, t_vars *vars)
{
	if (cmd->args[1])
	{
		if (ft_strncmp_a(cmd->args[1], "on") == 0)
		{
			vars->custom_prompt = 1;
			ft_perror_soft("custom_prompt", "turned on\n", vars, 0);
		}
		else if (ft_strncmp_a(cmd->args[1], "off") == 0)
		{
			vars->custom_prompt = 0;
			ft_perror_soft("custom_prompt", "turned off\n", vars, 0);
		}
		else
			ft_perror_soft("custom_prompt", "invalid argument(s)\n", vars, 0);
	}
	else
	{
		if (vars->custom_prompt)
			vars->custom_prompt = 0;
		else
			vars->custom_prompt = 1;
		vars->exit_code_int = 0;
	}
}

void	custom_perror(t_command_a *cmd, t_vars *vars)
{
	if (cmd->args[1])
	{
		if (ft_strncmp_a(cmd->args[1], "on") == 0)
		{
			vars->custom_flag = 1;
			ft_perror_soft("custom_perror", "turned on\n", vars, 0);
		}
		else if (ft_strncmp_a(cmd->args[1], "off") == 0)
		{
			vars->custom_flag = 0;
			ft_perror_soft("custom_perror", "turned off\n", vars, 0);
		}
		else
			ft_perror_soft("custom_perror", "invalid argument(s)\n", vars, 0);
	}
	else
	{
		if (vars->custom_flag)
			vars->custom_flag = 0;
		else
			vars->custom_flag = 1;
		vars->exit_code_int = 0;
	}
}
