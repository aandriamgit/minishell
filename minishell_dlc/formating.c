/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:32:52 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/28 18:35:06 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "expend/dep/dep.h"
#include "../utils/utils.h"

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void	modify_str(char **str, t_list *env_cp, t_vars	*vars)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_expend(*str);
	while (split[i])
	{
		if (check(split[i]) == 1 && split[i][0] != '\'')
		{
			if (split[i][0] == '\"')
				;
			else if (split[i][0] == '$')
				improved_expend(&split[i], env_cp, vars);
			else if (check_bloc(split[i]) == 0)
				improved_expend(&split[i], env_cp, vars);
		}
		i++;
	}
	free(*str);
	*str = join_no_space(split);
	free_split(&split);
}

void	some_modification(char **str, t_list *env_cp, t_vars *vars)
{
	char	**split;
	int		i;

	i = 0;
	split = split_take_quote(*str, ' ');
	while (split[i])
	{
		if (split[i][0] == '\"' && check(split[i]) == 1)
			ex_quote(&split[i], env_cp, vars);
		i++;
	}
	free(*str);
	*str = join_no_space(split);
	ft_free_tab(&split);
}

void	formating_quote(char **str, t_list *env_cp, t_vars	*vars)
{
	char	**split;
	int		i;

	i = 0;
	split = split_quote(*str, ' ');
	while (split[i])
	{
		if (check(split[i]) == 1)
		{
			if (check(split[i]) == 1)
				modify_str(&split[i], env_cp, vars);
		}
		i++;
	}
	free(*str);
	*str = join_with_space(split);
	free_split(&split);
}

void	formating(char **str, t_list *env_cp, t_vars	*vars)
{
	char	**split;
	int		i;

	i = 0;
	split = split_quote(*str, ' ');
	while (split[i])
	{
		if (check(split[i]) == 1)
		{
			some_modification(&split[i], env_cp, vars);
			if (check(split[i]) == 1)
			{
				if (i > 0 && check_her(split[i - 1], split[i], i) == 0)
					modify_str(&split[i], env_cp, vars);
				if (i == 0 && check_bloc(split[i]) == 0)
					modify_str(&split[i], env_cp, vars);
			}
		}
		i++;
	}
	free(*str);
	*str = join_with_space(split);
	free_split(&split);
}
