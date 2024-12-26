/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:09:28 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:34:34 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

static void	extras(t_command_a *cmd, t_vars *vars)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		if (cmd->args[i][0] == '-')
		{
			ft_perror_exit(cmd->args[i], "invalid option", vars, 2);
			return ;
		}
		i++;
	}
	i = 1;
	if (cmd->args[i])
	{
		while (cmd->args[i])
		{
			export_with_arg(&vars->env, cmd->args[i]);
			i++;
		}
	}
	else
		simple_export(vars->env);
	vars->exit_code_int = 0;
}

void	ft_export_w(t_command_a *cmd, t_vars *vars)
{
	extras(cmd, vars);
	ft_perror_exit(NULL, NULL, vars, 0);
}
