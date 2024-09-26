/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:32:35 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/26 13:44:48 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_command *creat_cmd(char *command)
{
	char **new_command;
	int i;
	t_command *cmd;

	i = 0;
	cmd = malloc(sizeof(t_command));
	new_command = ft_split(command, ' ');
	cmd->cmd = new_command[0];
	if ( new_command[1] && new_command[1][0] == '-')
	{
		cmd->option = new_command[1];
		i++;
	}
	else
	{
		cmd->option = NULL;
	}
	cmd->argument = down_argument(i, new_command);
	return (cmd);
}
