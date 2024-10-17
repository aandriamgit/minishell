/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheated_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:21 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/23 08:12:27 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_size(char *input)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '>' || input[i] == '<')
		{
			count++;
			if (input[i + 1] == input[i])
				i++;
		}
		i++;
	}
	count ++;
	return (count);
}

char *creat_bloc(int start, int end, char *input)
{
	char *bloc;
	int size;
	int i;

	i = 0;
	size = end - start + 1;
	bloc = malloc(sizeof(char) * (size + 1));
	while (start <= end)
	{
		bloc[i] = input[start];
		i++;
		start++;
	}
	bloc[i] = '\0';
	return (bloc);
}


char **cheated_split(char *input)
{
	char **new_input;
	int i;
	int j;
	int start;
	int end;

	j = 0;
	i = 0;
	start = 0;
	end = 0;
	new_input = malloc(sizeof(char *) * (count_size(input) + 1));
	if (!new_input)
		return (NULL);
	while(input[i])
	{
		start = i;
		while (input[i] != '>' && input[i] != '<' && input[i] != '\0')
			i++;
		if (input[i] == '>' || input[i] == '<')
		{

			end = i - 1;
			if (input[i + 1] == input[i])
				i++;
			new_input[j] = creat_bloc(start, end, input);
			j++;
		}
		if (input[i] == '\0')
		{
			end = i - 1;
			new_input[j] = creat_bloc(start, end, input);
			j++;
			break ;
		}
		i++;
	}
	new_input[j] = NULL;
	return (new_input);
}
