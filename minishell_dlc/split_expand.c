/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:01:36 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/04 15:50:26 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"

static int check(int i, char *str)
{
	i--;
	while (i <= 0)
	{
		if (str[i] == '$')
			return (1);
		else if (str[i] == '\'' || str[i] == '\"')
			return (0);
		i--;
	}
	return (0);
}



int ft_count_z(char *str)
{
	int i;
	int count;
	char c;

	count = 0;
	i = 0;
	c = '\0';
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			count++;
			c = str[i];
			i++;
			while (str[i] != c)
				i++;
			i++;
		}
		else
		{
			if (str[i] == '$')
			{
				count++;
				i++;
				while (str[i] && (str[i] != '\'' && str[i] != '\"' && str[i] != '$'))
					i++;
			}
			else
			{
				while (str[i] && (str[i] != '\'' && str[i] != '\"' && str[i] != '$'))
					i++;
				if (str[i] == '$' && check(i, str) == 1)
				{
					count++;
					while (str[i] && (str[i] != '\'' && str[i] != '\"' && str[i] != '$'))
						i++;
				}
			}
		}
	}
	return (count);
}

char **split_expand(char *str)
{
	char **new;
	int i;
	int j;
	int start;
	char c;

	i = 0;
	j = 0;
	start = 0;
	c = '\0';
	new = malloc(sizeof(char *) * (ft_count_z(str) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (str[i] && str[i] != c)
				i++;
			new[j] = ft_substr_p(start, i, str);
			j++;
			i++;
			start = i;
		}
		else
		{
			if (str[i] == '$')
			{
				i++;
				while (str[i] && (str[i] != '\'' && str[i] != '\"' && str[i] != '$'))
					i++;
				new[j] = ft_substr_p(start, i - 1, str);
				j++;
				start = i;
			}
			else
			{
				while (str[i] && (str[i] != '\'' && str[i] != '\"' && str[i] != '$'))
					i++;
				if (str[i] == '$')
				{
					i++;
					while (str[i] && (str[i] != '\'' && str[i] != '\"' && str[i] != '$'))
						i++;
					new[j] = ft_substr_p(start, i - 1, str);
					j++;
					start = i;
				}
				else
				{
					new[j] = ft_substr_p(start, i - 1, str);
					j++;
					start = i;
				}
			}
		}
	}
	new[j] = NULL;
	return (new);
}


