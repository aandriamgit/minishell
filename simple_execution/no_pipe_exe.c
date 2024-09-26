/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:30:40 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/25 17:34:34 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_special_cmd(t_vars *vars)
{
	if (ft_strncmp(vars->input, "cd") == 0)
		exec_cd(vars);
	else if (ft_strncmp(vars->input, "export") == 0)
		exec_export(vars);
	else if (ft_strncmp(vars->input, "unset") == 0)
		exec_unset(vars);
	else if (ft_strncmp(vars->input, "env") == 0)
		exec_env(vars);
	else if (ft_strncmp(vars->input, "echo") == 0)
		exec_echo(vars);
}

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
			terminate_nopipe_o(path, big_param, vars);
			exit(1);
		}
		if (execve(path, big_param, NULL) == -1)
		{
			printf("error : command not found: %s\n", big_param[0]);
			terminate_nopipe_o(path, big_param, vars);
			exit(1);
			ft_putstr_fd("askjdfhjksdafjklasfd", 1);
		}
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("error during fork_exec");
}
