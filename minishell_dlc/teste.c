/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:17:53 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 16:29:15 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	skip_x(int *i, char *str, char c)
{
	(*i)++;
	while (str[*i] && str[*i] != c)
		(*i)++;
	(*i)++;
}

static int	count_x(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && (str[i] != c))
		{
			count++;
			while (str[i] && (str[i] != c))
			{
				if (str[i] == '\'' || str[i] == '\"')
					skip_x(&i, str, str[i]);
				else
					i++;
			}
		}
		i++;
	}
	return (count);
}

void	mini_split_quote(char *str, char ***new, int *i, int *j)
{
	int	start;

	start = *i;
	if (str[*i] == '\'' || str[*i] == '\"')
		skip_x(i, str, str[*i]);
	else
		(*i)++;
	while (str[*i] && (str[*i] != ' '))
	{
		if (str[*i] == '\'' || str[*i] == '\"')
			skip_x(i, str, str[*i]);
		else
			(*i)++;
	}
	(*new)[*j] = ft_substr_p(start, *i - 1, str);
	(*j)++;
}

char	**split_quote(char *str, char c)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc (sizeof(char *) * (count_x(str, c) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] && str[i] != c)
			mini_split_quote(str, &new, &i, &j);
		else
			i++;
	}
	new[j] = NULL;
	return (new);
}
