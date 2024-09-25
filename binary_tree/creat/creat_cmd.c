/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:32:35 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/25 15:10:41 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_command *creat_cmd(char *command)
{
	char **new_command;
	int i;
	t_command *cmd;
	t_argument *tmp;

	i = 0;
	cmd = malloc(sizeof(t_command));
	new_command = ft_split(command, ' ');
	cmd->cmd = new_command[0];
	if (new_command[1][0] == '-' && new_command[1])
	{
		cmd->option = new_command[1];
		i++;
	}
	else
	{
		cmd->option = NULL;
	}
	tmp = cmd->argument;
	while (new_command[i])
	{
		tmp->arg = new_command[i];
		tmp = tmp->next;
		i++;
	}
	tmp = NULL;
	return (cmd);
}
