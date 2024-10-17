/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:45:32 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/25 14:23:37 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int count(char *cmd)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
		{
			if (cmd[i + 1] == cmd[i])
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

/*char *creat_bloc(int start, int end, char *input)
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
}*/

char **take_type(char *cmd)
{
	int i;
	char **new_cmd;
	int j;
	int start;
	int end;

	start = 0;
	end = 0;
	j = 0;
	i = 0;
	new_cmd = malloc(sizeof(char *) * (count(cmd) + 1));
	while(cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
		{
			start = i;
			if (cmd[i + 1] == cmd[i])
				end = i + 1;
			else
				end = start;
			new_cmd[j] = creat_bloc(start, end, cmd);
			j++;
		}
		i++;
	}
	return (new_cmd);
}
