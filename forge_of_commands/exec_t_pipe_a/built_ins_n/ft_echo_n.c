/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:10:06 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/05 13:27:57 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_n.h"

static int	is_valid_flag_n(const char *arg)
{
	int	i;

	if (arg[0] != '-' || arg[1] != 'n')
		return (0);
	i = 2;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	with_flag(char **args)
{
	char	**tab;
	int		i;

	tab = args;
	i = 2;
	while (tab[i])
	{
		ft_putstr_fd_a(tab[i], STDOUT_FILENO);
		if (tab[i + 1])
			ft_putstr_fd_a(" ", STDOUT_FILENO);
		i++;
	}
}

static void	extras(t_command_a *cmd, t_vars *vars)
{
	char	**tab;
	int		i;

	i = 1;
	(void)vars;
	if (cmd->args[1])
	{
		if (is_valid_flag_n(cmd->args[1]))
			with_flag(cmd->args);
		else
		{
			tab = cmd->args;
			while (tab[i])
			{
				ft_putstr_fd_a(tab[i], STDOUT_FILENO);
				if (tab[i + 1])
					ft_putstr_fd_a(" ", STDOUT_FILENO);
				i++;
			}
			ft_putstr_fd_a("\n", STDOUT_FILENO);
		}
	}
	else
		ft_putstr_fd_a("\n", STDOUT_FILENO);
	vars->exit_code_int = 0;
}

void	ft_echo_n(t_command_a *cmd, t_vars *vars)
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