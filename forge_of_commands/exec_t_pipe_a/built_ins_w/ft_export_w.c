/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:09:28 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/05 20:28:14 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

static int	is_valid_identifier(char *arg)
{
	int	i;

	if (!arg || !arg[0] || !ft_strncmp_a(arg, "SHLVL"))
		return (0);
	if (!(ft_isalpha(arg[0]) || arg[0] == '_'))
		return (0);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!(ft_isalpha(arg[i]) || arg[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static void	extras(t_command_a *cmd, t_vars *vars)
{
	int	i;

	i = 1;
	vars->exit_code_int = 0;
	if (cmd->args[i])
	{
		while (cmd->args[i])
		{
			if (!is_valid_identifier(cmd->args[i]))
				ft_perror_exit(cmd->args[i], "not a valid identifier\n", vars,
					1);
			else
				export_with_arg(&vars->env, cmd->args[i]);
			i++;
		}
	}
	else
		simple_export(vars->env);
}

void	ft_export_w(t_command_a *cmd, t_vars *vars)
{
	extras(cmd, vars);
	ft_perror_exit(NULL, NULL, vars, 0);
}
