/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:36:38 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/26 15:55:52 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include <stdio.h>

void	other_skip(int *i, char *str)
{
	while (*i >= 0 && (str[*i] == ' ' || str[*i] == '\t'))
		i--;
	i--;
}

int check_bloc(char *str)
{
	int i;
	char x;

	i = 0;
	x = '\0';
	if (str != NULL)
	{
		while (str[i])
		{
			if (str[i] == '$')
			{
				i--;
				if (i >= 0 && (str[i] == '\'' || str[i] == '\"'))
				{
					x = str[i];
					while (i >= 0 && str[i] == x)
					{
						if (str[i] == ' ' || str[i] == '\t')
							other_skip(&i, str);
						else
							i--;
					}
				}
				if ((i >= 0) && (str[i] == '<' || str[i] == '>'))
						return (1);
				else
					return (0);
			}
			i++;
		}
	}
	return (0);
}

int	check_her(char *s1, char *s2, int flag)
{
	int c;
	char x;
	int i;

	c = ft_strlen_p(s1) - 1;
	x = '\0';
	i = 0;


	if (s2[i] == '\'' || s2[i] == '\"')
	{
		x = s2[i];
		while (s2[i] && (s2[i] == x || s2[i] == '\t' || s2[i] == ' '))
			i++;
	}
	if (s2[i] == '$')
	{
		if (s1[c] == '\'' || s1[c] == '\"' || s1[c] == ' ' || s1[c] == '\t')
		{
			x = s1[c];
			while (c >= 0 && (s1[c] == x || s1[c] == ' ' || s1[c] == '\t'))
				c--;
		}
		if (c >= 0 && (s1[c] == '<' || s1[c] == '>') && flag > 0)
				return (1);
		else
			return (0);
	}
	else if (check_bloc(s2) == 1)
		return (1);
	return (0);
}
