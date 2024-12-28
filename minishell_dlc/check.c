/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:42:58 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/28 16:16:11 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"

void	check_quote(char **str)
{
	int		i;
	char	c;

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
				ft_putstr_p("unclosed quote >", 1);
				exit (1);
			}
		}
		i++;
	}
}

int	unclosed(int i, char **str)
{
	while ((*str)[i] && (*str)[i] == ' ')
		i++;
	if ((*str)[i] == '\0')
	{
		ft_putstr_p("unclosed pipe >", 1);
		exit(1);
	}
	return (i);
}

void	check_pipe(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '|')
			unclosed(i + 1, str);
		i++;
	}
}

void	check_input(char **str)
{
	check_quote(str);
	check_pipe(str);
}
