/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:45:09 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/26 13:43:36 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <time.h>


void	make_pipe(t_pipe **pipe, t_pipe *new_pipe)
{
	t_pipe *tmp;

	if (*pipe == NULL)
		*pipe = new_pipe;
	else
	{
		tmp = *pipe;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_pipe;
	}
}

t_pipe	*creat_pipe(char *format_input)
{
	t_pipe *pipe;
 
	pipe = malloc(sizeof(t_pipe));
	pipe->redirection = down_redirection(format_input);
	pipe->next = NULL;
	return (pipe);
}

t_pipe	*down_pipe(char *cmd_with_pipe)
{
	char **new_cmd_wp;
	t_pipe *pipe;
	int i;

	pipe = NULL;
	i = 0;
	new_cmd_wp = ft_split(cmd_with_pipe, '|');
	while (new_cmd_wp[i])
	{
		make_pipe(&pipe, creat_pipe(new_cmd_wp[i]));
		i++;
	}
	return (pipe);
}
