/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:23:18 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:34:12 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

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

void	ft_echo_w(t_command_a *cmd, t_vars *vars)
{
	char	**tab;
	int		i;

	i = 1;
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
	ft_perror_exit(NULL, NULL, vars, 0);
}
