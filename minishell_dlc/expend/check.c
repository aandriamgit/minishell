/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:36:38 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/23 18:04:38 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	other_skip(int *i, char *str)
{
	while (*i >= 0 && (str[*i] == ' ' || str[*i] == '\t'))
		i--;
	i--;
}

void	mini_check_bloc(int *i, char *str)
{
	char	x;

	x = '\0';
	if (i >= 0 && (str[*i] == '\'' || str[*i] == '\"'))
	{
		x = str[*i];
		while (*i >= 0 && str[*i] == x)
		{
			if (str[*i] == ' ' || str[*i] == '\t')
				other_skip(i, str);
			else
				(*i)--;
		}
	}
}

int	check_bloc(char *str)
{
	int		i;
	char	x;

	i = 0;
	x = '\0';
	if (str != NULL)
	{
		while (str[i])
		{
			if (str[i] == '$')
			{
				i--;
				mini_check_bloc(&i, str);
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

void	mini_check_her(int *c, char *s1)
{
	char	x;

	x = '\0';
	if (s1[*c] == '\'' || s1[*c] == '\"' || s1[*c] == ' ' || s1[*c] == '\t')
	{
		x = s1[*c];
		while (*c >= 0 && (s1[*c] == x || s1[*c] == ' ' || s1[*c] == '\t'))
			(*c)--;
	}
}

int	check_her(char *s1, char *s2, int flag)
{
	int		c;
	char	x;
	int		i;

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
		mini_check_her(&c, s1);
		if (c >= 0 && (s1[c] == '<' || s1[c] == '>') && flag > 0)
			return (1);
		else
			return (0);
	}
	else
		if (check_bloc(s2) == 1)
			return (1);
	return (0);
}
