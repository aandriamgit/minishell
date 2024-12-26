/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_bloc_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:29:22 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/26 16:03:55 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_pipe	*creat_bloc_pipe(char **str, t_vars	*vars)
{
	t_pipe	*p;

	p = malloc(sizeof(t_pipe));
	if (!p)
		return (NULL);
	p->redir = redirection(str);
	p->cmd = make_cmd(str);
	p->next = NULL;
	return (p);
}

void	creat_chain_of_pipe(t_pipe **old_list, t_pipe *new_list)
{
	t_pipe	*tmp;

	tmp = NULL;
	if (!(*old_list))
		*old_list = new_list;
	else
	{
		tmp = *old_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_list;
	}
}
