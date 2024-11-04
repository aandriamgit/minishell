/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:44:24 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/04 08:48:49 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_execve(char *cmd, char **argv)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (!cmd)
		{
			printf("error : command not found: %s\n", argv[0]);
			exit(1);
		}
		if (execve(cmd, argv, NULL) == -1)
		{
			ft_putstr_fd("error fork", 1);
			exit(1);
		}
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("error fork");
}
