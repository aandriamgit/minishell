/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:00:16 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/02 12:06:28 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../minishell_dlc/parsing.h"
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
		close_all_fds();
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
	close_all_fds();
	if (execve(cmd, argv, NULL) == -1)
	{
		ft_putstr_fd_a("error fork ft_execve_row\n", 1);
		exit(1);
	}
}

char	*test_path(char *mini_path, char *input)
{
	char	**res;
	char	*tmp;
	int		i;

	i = -1;
	res = NULL;
	if (mini_path)
		res = ft_split_a(mini_path, ':');
	while (mini_path && res[++i])
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
	}
	free(input);
	if (res)
		ft_free_tab(&res);
	input = NULL;
	return (NULL);
}

void	ft_execve_path(t_pipe_a *pipe_a, char *cmd, char **argv, t_vars *vars)
{
	char	*path;
	char	*path_mini;
	char	*mini_cmd;
	char	**env_lol;

	(void)pipe_a;
	path = NULL;
	mini_cmd = NULL;
	path_mini = ft_getenv("PATH", vars->env);
	if (cmd[0])
		mini_cmd = ft_strjoin_a("/", cmd);
	if (mini_cmd)
		path = test_path(path_mini, mini_cmd);
	free(path_mini);
	if (!path)
		ft_perror_exit(cmd, "command not found\n", vars, 127);
	else
	{
		close_all_fds();
		env_lol = ft_gen_env(vars->env);
		execve(path, argv, env_lol);
		free(path);
		ft_free_tab(&env_lol);
		ft_perror_exit(cmd, "execve failed\n", vars, 2);
	}
}
