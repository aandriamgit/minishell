/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:00:16 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/12 15:46:55 by aandriam         ###   ########.fr       */
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

static char	*test_path(char *path, char *input)
{
	char	**res;
	char	*tmp;
	int		i;

	i = 0;
	res = ft_split_a(path, ':');
	while (res[i])
	{
		tmp = ft_strjoin_a(res[i], input);
		if ((access(tmp, X_OK)) == 0)
		{
			ft_free_tab(&res);
			free(input);
			input = NULL;
			return (tmp);
		}
		free(tmp);
		i++;
	}
	free(input);
	ft_free_tab(&res);
	input = NULL;
	return (NULL);
}

void	ft_execve_path(char *cmd, char **argv, t_vars *vars)
{
	char	*path;
	char	*mini_cmd;
	char	*tmp;

	mini_cmd = ft_strjoin_a("/", cmd);
	path = test_path(getenv("PATH"), mini_cmd);
	if (!path)
	{
		tmp = ft_strjoin_a(cmd, "\n");
		ft_perror_row("command not found", tmp, vars);
	}
	else
		execve(path, argv, NULL);
}
