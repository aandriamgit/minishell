/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:30:40 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/22 17:57:35 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		free_res(char ***res);
static void	terminate_nopipe(char *path, char **big_param, t_vars *vars)
{
	free(path);
	free(vars->input);
	free(vars->log_dir);
	free(vars->history_dir);
	free_res(&big_param);
}

void	free_res(char ***res)
{
	int	i;

	i = 0;
	while ((*res)[i])
	{
		free((*res)[i]);
		i++;
	}
	free(*res);
}

char	*test(char *path, char *input)
{
	char	**res;
	char	*tmp;
	int		i;

	i = 0;
	res = ft_split(path, ':');
	while (res[i])
	{
		tmp = ft_strjoin(res[i], input);
		if ((access(tmp, X_OK)) == 0)
		{
			free_res(&res);
			free(input);
			input = NULL;
			return (tmp);
		}
		free(tmp);
		i++;
	}
	free(input);
	free_res(&res);
	input = NULL;
	return (NULL);
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
			printf("error : command not found: %s\n", big_param[0]);
			terminate_nopipe(path, big_param, vars);
			exit(1);
			ft_putstr_fd("askjdfhjksdafjklasfd", 1);
		}
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("error during fork_exec");
}
