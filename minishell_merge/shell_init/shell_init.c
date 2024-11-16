/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:24:19 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/16 11:38:23 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "shell_init.h"

void	vars_init(t_vars *vars, t_list **env_cpy)
{
	vars->log_dir = ft_strjoin(getenv("HOME"), "/.minishell_log");
	vars->history_dir = ft_strjoin(vars->log_dir, "/.minishell_history");
	vars->env = *env_cpy;
	vars->stderr_a = malloc(sizeof(t_stderr_a));
	vars->stderr_a->dir = ft_strjoin(vars->log_dir, "/.stderr_a_dir");
	vars->stderr_a->fd = 2;
	vars->heredoc_dir = ft_strjoin(vars->log_dir, "/.heredoc_dir");
	vars->quote_dir = ft_strjoin(vars->log_dir, "/.quote_dir");
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
