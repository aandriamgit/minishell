/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:54:34 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/18 17:40:21 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dep/dep.h"
#include "../parsing.h"

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
			new = ft_substr_ap(parameter, i + 1, ft_strlen_ap(parameter));
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
	if (tmp && tmp[1] != '"')
	{
		to_replace = ft_strdup_ap("");
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

int count_pp(char **str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
	}
	return(i);
}

void	expend(char	**str, t_list *env)
{
	char	**splited_a;
	char	*new;

	splited_a = ft_split_aa(*str, '$');
	if (count_pp(splited_a) == 1)
		mini_expend(&splited_a[0], env);
	else
		mini_expend(&splited_a[1], env);
	new = ft_strjoin_space(&splited_a);
	free(*str);
	*str = new;
}
