/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:32:52 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/10 14:48:44 by mravelon         ###   ########.fr       */
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
	split = split_expand(*str);
	while (split[i])
	{
		if (check(split[i]) == 1 && split[i][0] != '\'')
		{
			if (split[i][0] == '\"')
				ex_quote(&split[i], env_cp);
			else if (split[i][0] == '$')
				simple_expend(&split[i], env_cp);
			else
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
	split = simple_split(*str, ' ');
	while (split[i])
	{
		if (check(split[i]) == 1)
			modify_str(&split[i], env_cp);
		i++;
	}
	free(*str);
	*str = join_with_space(split);
	free_split(&split);
}
