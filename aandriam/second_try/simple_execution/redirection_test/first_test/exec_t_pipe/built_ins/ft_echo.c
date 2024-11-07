/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:25:55 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/07 15:08:39 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../first_test.h"

void	with_flag(char **args)
{
	char	**tab;
	int		i;

	tab = args;
	i = 2;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], STDOUT_FILENO);
		if (tab[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
}

void	ft_echo(t_command *cmd)
{
	char	**tab;
	int		i;

	i = 1;
	if (ft_strncmp(cmd->args[1], "-n") == 0)
		with_flag(cmd->args);
	else
	{
		tab = cmd->args;
		while (tab[i])
		{
			ft_putstr_fd(tab[i], STDOUT_FILENO);
			if (tab[i + 1])
				ft_putstr_fd(" ", STDOUT_FILENO);
			i++;
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	ft_perror(NULL, NULL);
}
