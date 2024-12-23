/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:36:38 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/21 11:55:58 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int check_bloc(char *str)
{
	int i;
	char x;

	i = 0;
	x = '\0';

			printf("str = %s\n", str);
	if (str != NULL)
	{
		while (str[i])
		{
			if (str[i] == '$')
			{
				if ((i > 0) && (str[i - 1] == '<' || str[i - 1] == '>'))
				{
					x = str[i - 1];
					//if (str[i - 2] == x)
						return (1);
					/*else
						return (0);*/
				}
			}
			else
				i++;
		}
	}
	return (0);
}

int	check_her(char *s1, char *s2, int flag)
{
	int c;
	char x;

	c = ft_strlen_p(s1);
	x = '\0';
	if (s2[0] == '$')
	{
		if ((s1[c - 1] == '<' || s1[c - 1] == '>') && flag > 0)
		{
			x = s1[c - 1];
		//	if (s1[c - 2] == x)
				return (1);
		}
		else
			return (0);
	}
	else
		if (check_bloc(s2) == 1)
			return(1);
	return (0);
}
