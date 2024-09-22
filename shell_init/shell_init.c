/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:03:09 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/22 12:58:49 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	vars_init(t_vars *vars)
{
	vars->log_dir = ft_strjoin(getenv("HOME"), "/.minishell_log");
	vars->history_dir = ft_strjoin(vars->log_dir, "/.minishell_history");
}

void	big_param_init(char ***big_param, t_vars vars)
{
	*big_param = malloc(sizeof(char *) * 3);
	if (*big_param == NULL)
		exit(0);
	(*big_param)[0] = ft_strdup("mkdir");
	(*big_param)[1] = ft_strdup(vars.log_dir);
	(*big_param)[2] = NULL;
}

void	terminate_shell_init(char **big_param)
{
	free(big_param[0]);
	free(big_param[1]);
	free(big_param);
}

void	fork_mkdir(char **big_param)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve("/bin/mkdir", big_param, NULL);
		exit(1);
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("fork error");
}
