/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:17:53 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/21 13:55:38 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int count_x(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char **simple_split(char *str, char c)
{
	int start;
	char **new;
	int i;
	int j;

	i = 0;
	j = 0;
	start = 0;
	new = malloc (sizeof(char *) * (count_x(str, c) + 1));
	if (!new)
		return (NULL);
	while(str[i])
	{
		if (str[i] != c)
		{
			start = i;
			i++;
			while (str[i] && str[i] != c)
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
