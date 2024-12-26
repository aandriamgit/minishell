/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_take_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:17:53 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/26 16:39:42 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

void	skip_y(int *i, char *str, char c)
{
	(*i)++;
	while (str[*i] && str[*i] != c)
		(*i)++;
	(*i)++;
}

static int count_quote_x(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c && str[i] == '\"')
		{
			count++;
			skip_y(&i, str, str[i]);
		}
		else if (str[i] && str[i] != c)
		{
			count++;
			while(str[i] && (str[i] != c && str[i] != '\"'))
			{
				if (str[i] == '\"')
				{
					count++;
					skip_y(&i, str, str[i]);
				}
				else
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

char **split_take_quote(char *str, char c)
{
	int start;
	char **new;
	int i;
	int j;

	i = 0;
	j = 0;
	start = 0;
	new = malloc (sizeof(char *) * (count_quote_x(str, c) + 1));
	if (!new)
		return (NULL);
	while(str[i])
	{
		if (str[i] && str[i] != c && str[i] == '\"')
		{
			start = i;
			skip_y(&i, str, str[i]);
		  	new[j] = ft_substr_p(start, i - 1, str);
			j++;
		}
		else if (str[i] && str[i] != c)
		{
			start = i;
			while (str[i] && (str[i] != '\"' && str[i] != c))
				i++;
			new[j] = ft_substr_p(start, i - 1, str);
			j++;
		}
		else
			i++;
	}
	new[j] = NULL;
	return (new);
}
