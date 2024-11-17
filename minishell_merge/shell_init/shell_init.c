/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:24:19 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/17 15:47:23 by aandriam         ###   ########.fr       */
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

static void	finding_quote(char **prev, char quote, int fd)
{
	int		i;
	char	*tmp;
	char	*lol;

	lol = ft_strjoin_free_a(*prev, "\n");
	tmp = get_next_line(fd);
	while (tmp)
	{
		i = 0;
		while (tmp[i])
		{
			if (tmp[i] == quote)
			{
				lol = ft_strjoin_free_a(lol, tmp);
				free(tmp);
				*prev = lol;
				return ;
			}
			i++;
		}
		lol = ft_strjoin_free_a(lol, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
}

static void	clean_prev(char **prev, int fd)
{
	int		i;
	char	*str;
	char	quote;

	i = 0;
	str = *prev;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			quote = str[i];
			i++;
			while (str[i] != quote)
			{
				if (!str[i])
				{
					finding_quote(prev, quote, fd);
					return ;
				}
				i++;
			}
		}
		i++;
	}
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
	clean_prev(&prev, fd);
	add_history(prev);
	while (prev)
	{
		free(prev);
		prev = get_next_line(fd);
		if (!prev)
			return ;
		prev[ft_strlen(prev) - 1] = '\0';
		clean_prev(&prev, fd);
		add_history(prev);
	}
	close(fd);
}
