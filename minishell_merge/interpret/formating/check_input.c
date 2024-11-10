/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:11:12 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/08 14:21:01 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void ft_putstr(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	check_quote(char **str)
{
	int i;
	char c;

	i = 0;
	c = '\0';
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' || (*str)[i] == '\"')
		{
			c = (*str)[i];
			i++;
			while ((*str)[i] && (*str)[i] != c)
				i++;
			if ((*str)[i] == '\0')
			{
				ft_putstr("unclosed quote >", 1);
				exit (1);
			}
		}
		i++;
	}
}

int unclosed(int i, char **str)
{
	while ((*str)[i] && (*str)[i] == ' ')
		i++;
	if ((*str)[i] == '\0')
	{
		ft_putstr("unclosed pipe >", 1);
		exit(1);
	}
	return (i);
}

void	check_pipe(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '|')
			unclosed(i + 1, str);			
		i++;
	}
}

void check_input(char **str)
{
	check_quote(str);
	check_pipe(str);
}
