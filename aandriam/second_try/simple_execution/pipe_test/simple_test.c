/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:46:46 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/01 16:47:12 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_test.h"

t_pipe	*gen_pipe_test(t_command *cmd, t_pipe *prev, t_pipe *next)
{
	t_pipe	*res;

	res = malloc(sizeof(t_pipe));
	if (!res)
		return (NULL);
	res->cmd = cmd;
	if (prev != NULL)
		res->prev = prev;
	else
		res->prev = NULL;
	if (next)
		res->next = next;
	else
		res->next = NULL;
	return (res);
}

void	add_pipe_next(t_pipe **first, t_pipe **second)
{
	t_pipe	*tmp;
	t_pipe	*lol;

	if (*first)
	{
		tmp = *first;
		tmp->next = *second;
	}
	if (*second)
	{
		lol = *second;
		lol->prev = tmp;
	}
}

void	free_t_pipe_again(t_pipe **p_test)
{
	t_pipe	*tmp;
	t_pipe	*tmp_again;

	tmp = *p_test;
	while (tmp)
	{
		tmp_again = tmp;
		tmp = tmp->next;
		free(tmp_again);
	}
}
