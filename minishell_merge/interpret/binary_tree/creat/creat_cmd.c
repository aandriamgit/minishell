/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:32:35 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/09 13:47:01 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../binary_tree.h"

int	lenght_char(char **new_command, int i)
{
	int	count;

	count = 0;
	while (new_command[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**rest_argument(char **command, int i)
{
	char	**new_command;
	int		j;

	j = 0;
	new_command = malloc(sizeof(char *) * (lenght_char(command, i)));
	if (!new_command)
		return (NULL);
	while (command[i])
	{
		new_command[j] = command[i];
		j++;
		i++;
	}
	new_command[j] = NULL;
	return (new_command);
}

t_command	*creat_cmd(char *command)
{
	char		**new_command;
	int			i;
	t_command	*cmd;

	i = 0;
	cmd = malloc(sizeof(t_command));
	new_command = ft_split(command, ' ');
	cmd->cmd = new_command[0];
	if (new_command[1] && new_command[1][0] == '-')
	{
		cmd->option = new_command[1];
		i++;
	}
	else
	{
		cmd->option = NULL;
	}
	cmd->arguments = rest_argument(new_command, i);
	return (cmd);
}
