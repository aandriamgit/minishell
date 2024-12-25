/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:32:52 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/23 13:44:37 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int check(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void modify_str(char **str, t_list *env_cp)
{
	char **split;
	int i;
	
	i = 0;
	split = split_expand_1(*str);
	while (split[i])
	{
		if (check(split[i]) == 1 && split[i][0] != '\'')
		{
			if (split[i][0] == '\"')
				ex_quote(&split[i], env_cp);
			else if (split[i][0] == '$')
			{
				expend(&split[i], env_cp);
			}
			else if (check_bloc(split[i]) == 0)
				expend(&split[i], env_cp);
		}
		i++;
	}
	free(*str);
	*str = join_no_space(split);
	free_split(&split);
}

void	formating(char **str, t_list *env_cp)
{
	char **split;
	int i;

	i = 0;
	split = split_quote(*str, ' ');
	while (split[i])
	{
		if (check(split[i]) == 1)
		{
			if (i > 0 && check_her(split[i - 1], split[i], i) == 0)
						modify_str(&split[i], env_cp);
			if (i == 0 && check_bloc(split[i]) == 0)
				modify_str(&split[i], env_cp);
		}
		i++;
	}
	free(*str);
	*str = join_with_space(split);
	free_split(&split);
}	
