/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:05:06 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:26:39 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"
#include "built_ins_n.h"

static void	extras(t_command_a *cmd, t_vars *vars)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		if (cmd->args[i][0] == '-')
		{
			ft_perror_soft(cmd->args[i], "invalid option", vars, 2);
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

void	ft_export_n(t_command_a *cmd, t_vars *vars)
{
	int	flag;
	int	save_stdout;
	int	save_stdin;

	save_stdout = dup(STDOUT_FILENO);
	save_stdin = dup(STDIN_FILENO);
	flag = 0;
	handle_redir(cmd->redir, vars, &flag);
	if (flag)
		extras(cmd, vars);
	dup2(save_stdout, STDOUT_FILENO);
	dup2(save_stdin, STDIN_FILENO);
	close(save_stdout);
	close(save_stdin);
}
