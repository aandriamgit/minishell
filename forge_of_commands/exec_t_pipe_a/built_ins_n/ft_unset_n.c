/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:22:20 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/05 16:42:24 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"
#include "built_ins_n.h"

static void	extras(t_command_a *cmd, t_vars *vars)
{
	int	i;

	if (cmd->args[1] && cmd->args[1][0] == '-' && cmd->args[1][1])
		ft_perror_soft(cmd->args[1], "invalid option\n", vars, 1);
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

void	ft_unset_n(t_command_a *cmd, t_vars *vars)
{
	int	flag;
	int	save_stdout;
	int	save_stdin;

	flag = 0;
	save_stdout = dup(STDOUT_FILENO);
	save_stdin = dup(STDIN_FILENO);
	handle_redir(cmd->redir, vars, &flag);
	if (flag)
		extras(cmd, vars);
	dup2(save_stdout, STDOUT_FILENO);
	dup2(save_stdin, STDIN_FILENO);
	close(save_stdout);
	close(save_stdin);
}
