/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:34:59 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 16:14:34 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "expend/dep/dep.h"

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			skip(str, &i);
		else if (str[i] == '$')
			return (1);
		else
			i++;
	}
	return (0);
}

void	mini_check_exp(char **other, int *j, t_list *cp_env, t_vars *vars)
{
	if (check(*other) == 1 && (*other)[0] != '\'')
	{
		if ((*other)[0] == '$')
			simple_expend(other, cp_env);
		else
			expend(other, cp_env, vars);
	}
	(*j)++;
}

void	check_expand(char **str, t_list *cp_env, t_vars	*vars)
{
	int		i;
	int		j;
	char	**other;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (check(str[i]) == 1)
		{
			other = split_expand(str[i]);
			while (other[j])
				mini_check_exp(&other[j], &j, cp_env, vars);
			free(str[i]);
			str[i] = ft_strjoin_space(&other);
		}
		i++;
	}
}
