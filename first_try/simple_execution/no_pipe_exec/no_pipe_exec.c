/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:56:51 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/11 10:03:09 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_special_cmd(t_vars *vars)
{
	if (ft_strncmp(vars->input, "cd") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "export") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "unset") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "env") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "echo") == 0)
		return (1);
	return (0);
}

void	fork_exec_nopipe(char *path, char **big_param, t_vars *vars)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (!path)
		{
			printf("error : command not found: %s\n", big_param[0]);
			terminate_nopipe(path, big_param, vars);
			exit(1);
		}
		if (execve(path, big_param, NULL) == -1)
		{
			terminate_nopipe(path, big_param, vars);
			exit(1);
		}
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("error during fork_exec");
}
