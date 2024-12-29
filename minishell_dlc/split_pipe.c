/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:29:34 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 17:05:49 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	count_pipe(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
			{
				if (str[i] == '\'' || str[i] == '\"')
					skip_x(&i, str, str[i]);
				else
					i++;
			}
		}
		else
			i++;
	}
	return (count);
}

void	init_pipe(int *i, int *j, int *start)
{
	*i = 0;
	*j = 0;
	*start = 0;
}

void	mini_split_pipe(int *i, char *str)
{
	if (str[*i] == '\'' || str[*i] == '\"')
		skip_x(i, str, str[*i]);
	else
		(*i)++;
}

void	mini_mini(int *i, char *str, char c)
{
	while (str[*i] && str[*i] != c)
		mini_split_pipe(i, str);
}

char	**split_pipe(char *str, char c)
{
	int		start;
	char	**new;
	int		i;
	int		j;

	init_pipe(&i, &j, &start);
	new = malloc (sizeof(char *) * (count_pipe(str, c) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
		{
			start = i;
			mini_mini(&i, str, c);
			new[j] = ft_substr_p(start, i - 1, str);
			j++;
		}
		else
			i++;
	}
	new[j] = NULL;
	return (new);
}
