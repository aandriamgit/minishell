/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:59:37 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/22 16:07:58 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_quote(char *cmd)
{
	int i;
	int quote;

	i = 0;
	quote = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
			quote++;
		i++;
	}
	return (quote / 2);
}

int count_allocation(char *cmd)
{
	int count;
	int i;

	check_quote(cmd);
	count = count_quote(cmd);
	i = 0;

	if (cmd[i] == '>')
	{
		count++;
		i++;
	}
	while (cmd[i])
	{
		if (cmd[i] == '|' || (cmd[i] == '>' && cmd[i + 1] != '>') || (cmd[i] == '<'))
		{
			if (i == 0)
				count++;
			else
				count += 2;
			i++;
		}
		else if (cmd[i] == '>' && cmd[i + 1] == '>')
		{
			count += 2;		
		}
		else if (cmd[i] == '&' && cmd[i + 1] == '>')
		{
			count += 2;
		}
		else if (cmd[i] == '2' && cmd[i + 1] == '>')
		{
			count += 2;
		}
		i++;
	}
	return (i + count);
}

char	*make_space(char *cmd)
{
	char *new_cmd;
	int i;
	int j;

	i = 0;
	j = 0;
	new_cmd = malloc(sizeof(char) * (count_allocation(cmd) + 1));
	if (cmd[i] == '>')
	{
		new_cmd[j] = cmd[i];
		j++;
		new_cmd[j] = ' ';
		j++;
		i++;
	}
	while (cmd[i])
	{
		if (cmd[i] == '"')
		{
			new_cmd[j] = ' ';
			j++;
			new_cmd[j] = cmd[i];
			i++;
			j++;
			while (cmd[i] != '"')
			{
				new_cmd[j] = cmd[i];
				j++;
				i++;
			}
			new_cmd[j] = cmd[i];
			i++;
			j++;
			new_cmd[j] = ' ';
			j++;
		}
		if (cmd[i] == '|' || (cmd[i] == '>' && cmd[i + 1] != '>') || (cmd[i] == '<'))
		{
			new_cmd[j] = ' ';
			j++;
			new_cmd[j] = cmd[i];
			j++;
			new_cmd[j] = ' ';
			j++;
		}
		else if ((cmd[i] == '>' && cmd[i + 1] == '>') || (cmd[i] == '&' && cmd[i + 1] == '>') || (cmd[i] == '2' && cmd[i + 1] == '>')
)
		{
			new_cmd[j] = ' ';
			j++;
			new_cmd[j] = cmd[i];
			j++;
			i++;
			new_cmd[j] = cmd[i];
			j++;
			new_cmd[j] = ' ';
			j++;
		}
		else
		{
			new_cmd[j] = cmd[i];
			j++;
		}
		i++;
	}
	new_cmd[j] = '\0';
	return (new_cmd);
}


char *formating(char *input)
{
	char *new_input;

	new_input = make_space(input);
	return (new_input);
}
