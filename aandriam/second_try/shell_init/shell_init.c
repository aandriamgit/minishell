/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:24:19 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/19 18:08:14 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "shell_init.h"

void	vars_init(t_vars *vars, char **env)
{
	vars->log_dir = ft_strjoin(getenv("HOME"), "/.minishell_log");
	vars->history_dir = ft_strjoin(vars->log_dir, "/.minishell_history");
	vars->env = env;
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

void	add_prev_history(t_vars *vars)
{
	char	*prev;
	int		fd;

	fd = open(vars->history_dir, O_RDONLY);
	prev = get_next_line(fd);
	if (!prev)
		return ;
	prev[ft_strlen(prev) - 1] = '\0';
	add_history(prev);
	while (prev)
	{
		free(prev);
		prev = get_next_line(fd);
		if (!prev)
			return ;
		prev[ft_strlen(prev) - 1] = '\0';
		add_history(prev);
	}
	close(fd);
}

void	exec_big_param(char **big_param)
{
	char	*path;
	char	*cmd;

	cmd = ft_strjoin("/", big_param[0]);
	path = test_path(getenv("PATH"), cmd);
	if (!path)
	{
		ft_putstr_fd("error : command not found: ", 1);
		ft_putstr_fd(big_param[0], 1);
		ft_putstr_fd("\n", 1);
		return ;
	}
	else
		ft_execve(path, big_param);
	free(path);
}
