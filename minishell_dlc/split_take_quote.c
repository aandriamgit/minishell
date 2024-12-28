/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_take_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:17:53 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/28 18:25:09 by mravelon         ###   ########.fr       */
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

void	mini_count_quote(char *str, char c, int *i, int *count)
{
	(*count)++;
	while (str[*i] && (str[*i] != c && (str[*i] != '\"' || str[*i] != '\'')))
	{
		if ((str[*i] == '\"') || (str[*i] == '\''))
		{
			(*count)++;
			skip_y(i, str, str[*i]);
		}
		else
			(*i)++;
	}
}

static int	count_quote_x(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c && ((str[i] == '\"') || (str[i] == '\'')))
		{
			count++;
			skip_y(&i, str, str[i]);
		}
		else if (str[i] && str[i] != c)
			mini_count_quote(str, c, &i, &count);
		else
			i++;
	}
	return (count);
}

void	mini_split_take(char *str, char ***new, int *i, int *j)
{
	char	c;
	int		start;

	start = 0;
	c = ' ';
	if (str[*i] && str[*i] != c && ((str[*i] == '\"') || (str[*i]) == '\''))
	{
		start = *i;
		skip_y(i, str, str[*i]);
		(*new)[*j] = ft_substr_p(start, *i - 1, str);
		(*j)++;
	}
	else if (str[*i] && str[*i] != c)
	{
		start = *i;
		while (str[*i] && (str[*i] != '\"' && str[*i] != c && str[*i] != '\''))
			(*i)++;
		(*new)[*j] = ft_substr_p(start, *i - 1, str);
		(*j)++;
	}
	else
		(*i)++;
}

char	**split_take_quote(char *str, char c)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc (sizeof(char *) * (count_quote_x(str, c) + 1));
	if (!new)
		return (NULL);
	while (str[i])
		mini_split_take(str, &new, &i, &j);
	new[j] = NULL;
	return (new);
}
