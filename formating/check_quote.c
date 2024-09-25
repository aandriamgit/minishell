/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:19:11 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/20 13:19:32 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_quote(char *input)
{
	int i;
	int j;
	int flag;

	j = 0;
	i = 0;
	flag = 1;

	if (input[ft_strlen(input) - 1] == '|')
	{
		printf("pipe>");
		exit (1);
	}
	while (input[i])
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			j = i + 1;
				while (input[j] && flag == 1)
				{
					if (input[j] == input[i])
						flag = 0;
					j++;
				}
			if (flag == 1)
			{
				write(1, "quote>", 6);
				exit(1);
			}
		}
		i++;
	}
	return (0);
}
