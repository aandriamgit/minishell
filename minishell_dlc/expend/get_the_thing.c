/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_thing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:04:55 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/28 07:30:54 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "dep/dep.h"

static int	found_it(char *tmp, char *parameter)
{
	int	i;

	i = 0;
	while (parameter[i])
	{
		if (parameter[i] == '=')
		{
			if (ft_strncmp_ap(tmp, parameter, i) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

static void	replace_it(char **to_replace, char *parameter)
{
	int		i;
	char	*new;

	i = 0;
	while (parameter[i])
	{
		if (parameter[i] == '=')
		{
			new = ft_substr_a(parameter, i + 1, ft_strlen_ap(parameter));
			if (!new)
				return ;
			free(*to_replace);
			*to_replace = new;
		}
		i++;
	}
}

static void	mini_expend(char **str, t_list *env)
{
	char	*to_replace;
	char	*tmp;
	t_list	*voyager_one;

	tmp = *str;
	if (tmp && tmp[1] && tmp[1] != '"' && tmp[1] != ' ')
	{
		if (tmp[0] == '$')
			tmp++;
		to_replace = ft_strdup_a("");
		voyager_one = env;
		while (voyager_one)
		{
			if (found_it(tmp, voyager_one->cmd))
			{
				replace_it(&to_replace, voyager_one->cmd);
				break ;
			}
			voyager_one = voyager_one->next;
		}
		free(*str);
		*str = to_replace;
	}
}

char	*get_the_thing(char *tmp_str, int *j, t_vars *vars)
{
	char	*tmp;
	int		i;
	int		lol;

	i = 0;
	lol = *j;
	while (tmp_str[*j] && tmp_str[*j] != ' ')
	{
		(*j)++;
		i++;
		if (tmp_str[*j] == '$')
			break ;
	}
	tmp = ft_substr_a(tmp_str, lol, i);
	mini_expend(&tmp, vars->env);
	return (tmp);
}
