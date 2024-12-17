/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:29:34 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/13 16:37:47 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int count_pipe(char *str, char c)
{
	int i;
	int count;
	char x;

	x = '\0';
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
				{
					x = str[i];
					i++;
					while(str[i] != x)
						i++;
					i++;
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

char **split_pipe(char *str, char c)
{
	int start;
	char **new;
	char x;
	int i;
	int j;

	i = 0;
	j = 0;
	x = '\0';
	start = 0;
	new = malloc (sizeof(char *) * (count_pipe(str, c) + 1));
	if (!new)
		return (NULL);
	while(str[i])
	{
		if (str[i] != c)
		{
			start = i;
			i++;
			while (str[i] && str[i] != c)
			{
				if (str[i] == '\'' || str[i] == '\"')
				{
					x = str[i];
					i++;
					while (str[i] != x)
						i++;
					i++;
				}
				else
					i++;
			}
			new[j] = ft_substr_p(start, i - 1, str);
			j++;
		}
		else
			i++;
	}
	new[j] = NULL;
	return (new);
}
