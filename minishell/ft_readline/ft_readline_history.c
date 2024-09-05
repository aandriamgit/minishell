/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:23:39 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/05 16:39:30 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int read_size_buffer(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int simple_read_size(char *str)
{
	int i;

	i = 0;
	while(str[i])
	   i++;
	return (i);
}


void ft_readline_history(char *buffer, char **tmp)
{
	char *stock;

	if (buffer[0] != '\n')
	{
		if (*tmp == NULL)
			*tmp = ft_strdup(buffer);
		else
		{
			stock = ft_strdup(*tmp);
			free(*tmp);
			*tmp = ft_strjoin(stock, buffer);
			free(stock);
		}
	}
}
