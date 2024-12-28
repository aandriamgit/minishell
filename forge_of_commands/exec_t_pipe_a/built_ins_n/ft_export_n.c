/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:05:06 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/28 09:09:34 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"
#include "built_ins_n.h"

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
	while (cmd->args[i])
	{
		if (!is_valid_identifier(cmd->args[i]))
		{
			ft_perror_soft(cmd->args[i], "invalid identifier\n", vars, 1);
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
