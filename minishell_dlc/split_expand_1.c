/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expand_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:28:06 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/23 13:38:23 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"
#include <stdio.h>

static int check(int i, char *str)
{
	i--;
	while (i >= 0)
	{
		if (str[i] == '$')
			return (1);
		else if (str[i] == '\'' || str[i] == '\"')
			return (0);
		i--;
	}
	return (0);
}

int count_expand(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
				count++;
			skip_x(&i, str, str[i]);
		}
		else
		{
			if (str[i] && str[i] == '$')
			{
				count++;
				i++;
				while (str[i] && (str[i] == '\'' && str[i] != '\"' && str[i] != '$'))
					i++;
			}
			else
			{
				if (str[i])
					count++;
				while (str[i] && (str[i] != '\'' && str[i] != '\"' && str[i] != '$'))
					i++;
				if (str[i] && str[i] == '$' && check(i, str) == 0)
				{
					while(str[i] && (str[i] != '\'' && str[i] != '\"' && str[i] != '$'))
						i++;
				}
			}
		}
	}
	return (count);
}

char **split_expand_1(char *str)
{
	int i;
	int j;
	int start;
	char **new;

	i = 0;
	j = 0;
	start = 0;
	new = malloc(sizeof(char *) * (count_expand(str) + 1));
	if (!new)
		return (new);
	while (str[i])
	{
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
		{
			start = i;
			skip_x(&i, str, str[i]);
			new[j] = ft_substr_p(start, i - 1, str);
			j++;
		}
		else
		{
			if (str[i] == '$')
			{
				start = i;
				i++;
				while (str[i] && (str[i] != '\"' && str[i] != '\'' && str[i] != '$'))
					i++;
				new[j] = ft_substr_p(start, i - 1, str);
				j++;
			}
			else
			{
				start = i;
				while (str[i] && (str[i] != '\'' && str[i] != '\"' && str[i] != '$'))
					i++;
				if (str[i] == '$' && check(i, str) == 0)
				{
					while (str[i] && (str[i] != '\'' && str[i] == '\"' && str[i] != '$'))
						i++;
					new[j] = ft_substr_p(start, i - 1, str);
					j++;
				}
				else
				{
					new[j] = ft_substr_p(start, i - 1, str);
					j++;
				}
			}
		}
	}
	new[j] = NULL;
	return (new);
}
