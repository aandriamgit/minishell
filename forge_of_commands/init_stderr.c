/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stderr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:46:36 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/13 14:28:47 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forge_of_commands.h"
#include <stdio.h>

static void	rm_that(char *stderr_a)
{
	char	**args;
	char	*cmd;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		args = malloc(sizeof(char *) * 4);
		args[0] = ft_strdup_a("rm");
		args[1] = ft_strdup_a("-rf");
		args[2] = ft_strdup_a(stderr_a);
		args[3] = NULL;
		cmd = ft_strdup_a("/bin/rm");
		execve(cmd, args, NULL);
	}
	else if (pid < 0)
		perror("rm_that pid");
	else
		wait(NULL);
}

static void	mkdir_that(char *stderr_a)
{
	char	**args;
	char	*cmd;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		args = malloc(sizeof(char *) * 3);
		args[0] = ft_strdup_a("mkdir");
		args[1] = ft_strdup_a(stderr_a);
		args[2] = NULL;
		cmd = ft_strdup_a("/bin/mkdir");
		execve(cmd, args, NULL);
	}
	else if (pid < 0)
		perror("mkdir_that pid");
	else
		wait(NULL);
}

void	init_stderr(t_vars *vars)
{
	rm_that(vars->stderr_a);
	mkdir_that(vars->stderr_a);
}
