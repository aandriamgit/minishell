/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:07:50 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/20 14:49:14 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

static void	extras(t_command_a *cmd, t_vars *vars)
{
	if (cmd->args[1])
	{
		if (cmd->args[1][0] == '-')
			ft_perror_exit(cmd->args[1], "invalid option\n", vars, 1);
		else
			ft_perror_exit(cmd->args[0], "too much argument(s)\n", vars, 1);
	}
	else
		display_env_p(vars->env);
	vars->exit_code_int = 0;
}

void	ft_env_w(t_command_a *cmd, t_vars *vars)
{
	extras(cmd, vars);
	ft_perror_exit(NULL, NULL, vars, 0);
}
