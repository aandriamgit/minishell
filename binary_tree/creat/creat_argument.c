/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:01:15 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/26 13:40:09 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <time.h>


void make_argument(t_argument **argument, t_argument *new_argument)
{
	t_argument *tmp;

	if (*argument == NULL)
		*argument = new_argument;
	else
	{
		tmp = *argument;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_argument;
	}
}

t_argument *creat_argument(char *arg)
{
	t_argument *argument;

	argument = malloc(sizeof(t_argument));
	argument->arg = arg;
	argument->next = NULL;
	return (argument);
}

t_argument	*down_argument(int i, char **arg)
{
	t_argument *argument;

	argument = NULL;
	while(arg[i])
	{
		make_argument(&argument, creat_argument(arg[i]));
		i++;
	}
	return (argument);
}

