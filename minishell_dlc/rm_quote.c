/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:55:24 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/15 14:15:40 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_quotes(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int count_quote(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			count++;
		i++;
	}
	return (count);
}

void	rm_quote(char **str)
{
	char *new;
	int i;
	int j;

	i = 0;
	j = 0;
	new = malloc (sizeof(char) * (count_quote(*str) + 1));
	if (!new)
		return ;
	while ((*str)[i])
	{
		if ((*str)[i] != '\'' && (*str)[i] != '\"')
		{
			new[j] = (*str)[i];
			j++;
		}
		i++;
	}
	free (*str);
	(*str) = ft_strdup_p(new);
	free (new);
}
