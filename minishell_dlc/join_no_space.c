/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_no_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:22:44 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/04 17:26:17 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_no_space(char **str)
{
	int i;
	int j;
	int count;

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
		j = 0;
		i++;
	}
	return (count);
}

char	*join_no_space(char **str)
{
	int i;
	int j;
	int k;
	char *new;

	k = 0;
	j = 0;
	i = 0;
	new = malloc(sizeof(char) * (count_no_space(str) + 1));
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
		j = 0;
		i++;
	}
	new[k] = '\0';
	return (new);
}
