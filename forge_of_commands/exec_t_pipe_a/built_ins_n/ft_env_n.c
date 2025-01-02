/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:40:59 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/02 15:55:10 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"
#include "built_ins_n.h"

static void	extras(t_command_a *cmd, t_vars *vars)
{
	if (cmd->args[1])
	{
		if (cmd->args[1][0] == '-')
			ft_perror_soft(cmd->args[1], "invalid option\n", vars, 1);
		else
			ft_perror_soft(cmd->args[0], "too much argument(s)\n", vars, 1);
	}
	else
	{
		display_env_p(vars->env);
		vars->exit_code_int = 0;
	}
}

void	ft_env_n(t_command_a *cmd, t_vars *vars)
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
