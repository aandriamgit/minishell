/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:58:46 by mravelon          #+#    #+#             */
/*   Updated: 2024/10/11 14:47:02 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void display_list(t_list **list)
{
	t_list *tmp;
	
	tmp = *list;
	while (tmp)
	{
		printf("%s\n", tmp->parameter);
		tmp = tmp->next;
	}
}