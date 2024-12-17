/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_chain_of_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:24:59 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/28 15:20:51 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void creat_chain_of_list(t_list **old_list, t_list *new_list)
{
	t_list *tmp;
	
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
