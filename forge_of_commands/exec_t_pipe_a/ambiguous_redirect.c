/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:24:07 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/04 18:37:06 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_t_pipe_a.h"

static int	check_ambiguous(char *dup_file, t_vars *vars)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup_a(dup_file);
	if (tmp[0] != '"')
	{
		improved_expend(&tmp, vars->env, vars);
		while (tmp[i])
		{
			if (tmp[i] == ' ')
			{
				free(tmp);
				return (1);
			}
			i++;
		}
	}
	free(tmp);
	return (0);
}

static int	extra(char **dup_file, int i, char **file, t_vars *vars)
{
	char	*tmp_dup_file;

	tmp_dup_file = *dup_file;
	while (tmp_dup_file[++i])
	{
		if (tmp_dup_file[i] == '$')
		{
			if (check_ambiguous(tmp_dup_file, vars))
			{
				free(*dup_file);
				*dup_file = NULL;
				return (1);
			}
			else
			{
				rm_quote(file);
				modify_str(file, vars->env, vars);
				free(*dup_file);
				*dup_file = NULL;
				return (0);
			}
		}
	}
	return (0);
}

int	ambiguous_redirect(char **file, t_vars *vars)
{
	int		i;
	char	*dup_file;

	i = -1;
	dup_file = ft_strdup_a(*file);
	while (dup_file[++i])
	{
		if (dup_file[i] == ' ')
		{
			if (dup_file[0] == '\'' || dup_file[0] == '\"')
				rm_quote(file);
			free(dup_file);
			return (0);
		}
	}
	i = -1;
	if (extra(&dup_file, i, file, vars))
		return (1);
	if (dup_file && (dup_file[0] == '\'' || dup_file[0] == '\"'))
		rm_quote(file);
	free(dup_file);
	return (0);
}
