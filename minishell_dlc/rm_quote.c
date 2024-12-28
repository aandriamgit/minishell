/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:55:24 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 13:07:23 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_quotes(char *str)
{
	int		i;
	char	x;

	i = 0;
	x = '\0';
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				x = str[i];
				i++;
				while (str[i] != x)
					i++;
				if (str[i] == x)
					return (1);
			}
			i++;
		}
	}
	return (0);
}

void	skip_count(char *str, int *i, int *count)
{
	char	x;

	x = '\0';
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		x = str[*i];
		(*i)++;
		while (str[*i] != x)
		{
			(*i)++;
			(*count)++;
		}
		(*i)++;
	}
	else
	{
		(*i)++;
		(*count)++;
	}
}

int	count_quote(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
		skip_count(str, &i, &count);
	return (count);
}

void	mini_rm_quote(char *str, char **new, int *i, int *j)
{
	char	x;

	x = '\0';
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		x = str[*i];
		(*i)++;
		while (str[*i] != x)
		{
			(*new)[*j] = str[*i];
			(*i)++;
			(*j)++;
		}
		(*i)++;
	}
	else
	{
		(*new)[*j] = str[*i];
		(*j)++;
		(*i)++;
	}
}

void	rm_quote(char **str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (count_quote(*str) + 1));
	if (!new)
		return ;
	while ((*str)[i])
		mini_rm_quote(*str, &new, &i, &j);
	new[count_quote(*str)] = '\0';
	free(*str);
	(*str) = ft_strdup_p(new);
	free(new);
}
