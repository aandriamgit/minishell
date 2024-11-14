/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:25:20 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 11:26:11 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forge_of_commands.h"

static void	show_errors(t_vars *vars)
{
	pid_t	pid;
	char	**args;

	pid = fork();
	if (pid == 0)
	{
		args = malloc(sizeof(char *) * 3);
		args[0] = ft_strdup_a("cat");
		args[1] = vars->stderr_a->dir;
		args[2] = NULL;
		ft_execve_path(args[0], args, vars);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
}

void	terminus(t_pipe_a **pipe_a, t_vars *vars)
{
	show_errors(vars);
	ft_free_t_pipe_a(*pipe_a);
	ft_free_t_pipe_again(pipe_a);
}
