/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_with_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:50:28 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/23 18:13:29 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_join(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

int	count_join(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			count++;
			j++;
		}
		if (str[i + 1] != NULL)
			count++;
		j = 0;
		i++;
	}
	return (count);
}

void	mini_join(char **new, int *k)
{
	(*new)[*k] = ' ';
	(*k)++;
}

char	*join_with_space(char **str)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	init_join(&i, &j, &k);
	new = malloc(sizeof(char) * (count_join(str) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		while (str[i][j])
		{
			new[k] = str[i][j];
			k++;
			j++;
		}
		if (str[i + 1] != NULL)
			mini_join(&new, &k);
		j = 0;
		i++;
	}
	new[k] = '\0';
	return (new);
}
