/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:54:01 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/21 18:18:13 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>

static int	ft_count(char **str)
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

void	ft_free_p(char ***str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
	*str = NULL;
}

char *ft_strjoin_space(char ***str)
{
	int i;
	char *new;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	new = malloc (sizeof(char) * (ft_count(*str) + 1));
	if (!new)
		return (NULL);
	while ((*str)[i])
	{
		while ((*str)[i][j])
		{
			new[k] = (*str)[i][j];
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	new[k] = '\0';
	ft_free_p(str);
	return (new);
}
