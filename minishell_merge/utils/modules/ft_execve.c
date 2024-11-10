/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:00:16 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/10 15:27:12 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	ft_execve_fork(char *cmd, char **argv)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (!cmd)
		{
			ft_putstr_fd_a("error : command not found:", 1);
			ft_putstr_fd_a(argv[0], 1);
			ft_putstr_fd_a("\n", 1);
			exit(1);
		}
		if (execve(cmd, argv, NULL) == -1)
		{
			ft_putstr_fd_a("error ft_execve_row\n", 1);
			exit(1);
		}
	}
	else if (pid > 0)
		wait(NULL);
	else
		ft_putstr_fd_a("error ft_execve_row\n", 1);
}

void	ft_execve_row(char *cmd, char **argv)
{
	if (execve(cmd, argv, NULL) == -1)
	{
		ft_putstr_fd_a("error fork ft_execve_row\n", 1);
		exit(1);
	}
}
