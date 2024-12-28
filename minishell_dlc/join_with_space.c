/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_with_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:50:28 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/28 16:11:34 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	mini_join_s(char **str, char **new, int i, int *k)
{
	if (str[i + 1] != NULL)
	{
		(*new)[*k] = ' ';
		(*k)++;
	}
}

char	*join_with_space(char **str)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	k = 0;
	j = 0;
	i = 0;
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
		mini_join_s(str, &new, i, &k);
		j = 0;
		i++;
	}
	new[k] = '\0';
	return (new);
}
