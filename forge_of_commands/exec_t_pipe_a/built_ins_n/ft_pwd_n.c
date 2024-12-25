/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:47:02 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:33:08 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_n.h"

static void	extras(t_command_a *cmd, t_vars *vars)
{
	char	buffer[1024];

	if (cmd->args[1] && cmd->args[1][0] == '-')
		ft_perror_soft(cmd->args[1], "invalid option\n", vars, 1);
	else
	{
		getcwd(buffer, 1024);
		ft_putstr_fd_a(buffer, STDOUT_FILENO);
		ft_putstr_fd_a("\n", STDOUT_FILENO);
	}
	vars->exit_code_int = 0;
}

void	ft_pwd_n(t_command_a *cmd, t_vars *vars)
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
