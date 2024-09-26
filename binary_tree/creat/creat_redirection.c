/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:53:30 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/26 13:42:41 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
//il faut identifier les redirections 

void make_redirection(t_redirection **redirection, t_redirection *new_redirection)
{
	t_redirection *tmp;

	if (*redirection == NULL)
		*redirection = new_redirection;
	else
	{
		tmp = *redirection;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new_redirection;
	}
}

t_redirection	*creat_redirection(char *cmd, char *type_of_redirection)
{
	t_redirection *redirection;

	redirection = malloc(sizeof(t_redirection));
	redirection->type_of_redirection = type_of_redirection;
	redirection->cmd = creat_cmd(cmd);
	return (redirection);
}

t_redirection *down_redirection(char *cmd_with_redirection)
{
	char **new_cmd_wr;
	int i;
	char **type;
	t_redirection *redirection;

	redirection = NULL;
	i = 0;
	type = take_type(cmd_with_redirection);
	new_cmd_wr = cheated_split(cmd_with_redirection);
	while (new_cmd_wr[i])
	{
		make_redirection(&redirection, creat_redirection(new_cmd_wr[i], type[i]));
		i++;
	}
	return (redirection);
}
