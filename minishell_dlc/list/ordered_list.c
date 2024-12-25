/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:16:36 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/25 14:17:48 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include "../../minishell.h"
#include <stdio.h>


int mini(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ordered_list(t_list **list)
{
	t_list	*tmp;
	char	*stock;
	t_list	*prev;
	t_list	*next_y;
	t_list	*next_x;
	int c;

	stock = NULL;
	prev = NULL;
	next_x = NULL;
	next_y = NULL;
	tmp = *list;
	c = 0;
	while ((*list) && (*list)->next)
	{
		prev = (*list);
		c = mini((*list)->arg, (*list)->next->arg);
		if (c > 0)
		{
			
		}
		else
		{
			(*list) = (*list)->next;
		}
	}
	(*list) = tmp;
	display_export_list(list);
}


