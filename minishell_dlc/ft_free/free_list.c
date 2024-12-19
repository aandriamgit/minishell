/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:49:02 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/19 16:50:12 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void free_node_list(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	if (tmp->arg)
	{
		free(tmp->arg);
		tmp->arg = NULL;
	}
	if(tmp->cmd)
	{
		free(tmp->cmd);
		tmp->cmd = NULL;
	}
	if(tmp->parameter)
	{
		free(tmp->parameter);
		tmp->parameter = NULL;
	}
	free(tmp);
	tmp = NULL;
}
