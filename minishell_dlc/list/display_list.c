/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:58:46 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/29 16:40:17 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void display_list(t_list **list)
{
	t_list *tmp;
	
	tmp = *list;
	while (tmp)
	{
		printf("arg:%s", tmp->arg);
		if (tmp->assignation == 1)
		{
	//		printf("%s", "=");
			printf("\tparam:%s\n", tmp->parameter);
		}
		else
			printf("\n");
		tmp = tmp->next;
	}
}