/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:55:55 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 08:39:13 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_built_ins_w.h"

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

void	ft_echo_w(t_command_a *cmd, t_vars *vars)
{
	char	**tab;
	int		i;

	i = 1;
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
	ft_perror_row(NULL, NULL, vars);
}
