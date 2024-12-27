/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:54:01 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 18:38:04 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
		i++;
	}
	return (count + i - 1);
}

void	ft_free(char ***str)
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

void	mini_join_p(int *i, int *k, char **str, char **new)
{
		if (str[*i + 1] != NULL)
		{
			(*new)[*k] = ' ';
			(*k)++;
		}
		(*i)++;
}

char *ft_strjoin_p(char ***str)
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
		mini_join_p(&i, &k, *str, &new);
		j = 0;
	}
	new[k] = '\0';
	ft_free(str);
	return (new);
}
