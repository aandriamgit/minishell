/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:24:07 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/28 09:03:21 by aandriam         ###   ########.fr       */
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
		modify_str(&tmp, vars->env, vars);
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

static int	extra(char *dup_file, int i, char **file, t_vars *vars)
{
	while (dup_file[++i])
	{
		if (dup_file[i] == '$')
		{
			if (check_ambiguous(dup_file, vars))
			{
				free(dup_file);
				return (1);
			}
			else
			{
				rm_quote(file);
				modify_str(file, vars->env, vars);
				free(dup_file);
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
			free(dup_file);
			return (1);
		}
	}
	i = -1;
	if (extra(dup_file, i, file, vars))
		return (1);
	free(dup_file);
	return (0);
}
