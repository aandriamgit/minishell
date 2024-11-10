/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:07:40 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/10 17:29:20 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	add_redir_end(t_redirection_a **res, t_redirection_a **to_add)
{
	t_redirection_a	*voyager_one;
	t_redirection_a	*tmp;

	voyager_one = *res;
	tmp = voyager_one;
	while (voyager_one)
	{
		tmp = voyager_one;
		voyager_one = voyager_one->next;
	}
	if (tmp)
		tmp->next = *to_add;
	else
		*res = *to_add;
}

void	add_pipe_a(t_pipe_a **p_test, t_pipe_a **to_add)
{
	t_pipe_a	*voyager_one;
	t_pipe_a	*tmp;

	voyager_one = *p_test;
	tmp = voyager_one;
	while (voyager_one)
	{
		tmp = voyager_one;
		voyager_one = voyager_one->next;
	}
	if (tmp)
		tmp->next = *to_add;
	else
		*p_test = *to_add;
}
