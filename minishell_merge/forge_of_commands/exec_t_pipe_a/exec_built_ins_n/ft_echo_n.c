/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:49:15 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/15 11:17:49 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_built_ins_n.h"

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
		if (ft_strncmp_a(cmd->args[1], "-n") == 0)
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
}

void	ft_echo_n(t_command_a *cmd, t_vars *vars)
{
	int	saved_stdout;

	saved_stdout = dup(STDOUT_FILENO);
	extras(cmd, vars);
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
	{
		perror("Erreur de restauration de stdout\n");
		close(saved_stdout);
	}
	close(saved_stdout);
}
