/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:03:37 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/28 14:00:57 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"

void	skip(char *str, int *i)
{
	char c;

	c = str[*i];
	(*i)++;
	while (str[*i] != c)
		(*i)++;
	(*i)++;
}

int	space(int i, char *str)
{
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
			skip(str, &i);
		else if (str[i] && str[i] == ' ')
		{
			if (i != 0 && space(i, str) == 1 && str[i - 1] != ' ')
				count++;
			while (str[i] == ' ')
				i++;
		}
		else if (str[i])
			i++;
	}
	if (i != 0)
		count++;
	return (count);
}

char **ft_split_na(char *str)
{
	int i;
	int j;
	char **new;
	int	start;
	int end;

	j = 0;
	new = malloc (sizeof(char *) * (count(str) + 1));
	if (!new)
		return (NULL);
	i = 0;
	end = 0;
	while (str[i] == ' ')
		i++;
	start = i;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			skip(str, &i);
		else if (str[i] == ' ')
		{
			new[j] = ft_substr_p(start, i - 1, str);
			j++;
			while (str[i] == ' ')
				i++;
			if (str[i])
				start = i;
		}
		else if (str[i])
			i++;
	}
	if (i != 0)
	{
		new[j] = ft_substr_p(start, i - 1, str);
		j++;
	}
	new[j] = NULL;
	return (new);
}
