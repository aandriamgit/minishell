/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:05:50 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/20 14:54:07 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

static void	extras(t_command_a *cmd, t_vars *vars)
{
	int	i;

	if (cmd->args[1] && cmd->args[1][0] == '-')
		ft_perror_exit(cmd->args[1], "invalid option\n", vars, 1);
	else
	{
		i = 0;
		while (cmd->args[i])
		{
			unset_p(&vars->env, cmd->args[i]);
			i++;
		}
	}
	vars->exit_code_int = 0;
}

void	ft_unset_w(t_command_a *cmd, t_vars *vars)
{
	extras(cmd, vars);
	ft_perror_exit(NULL, NULL, vars, 0);
}
