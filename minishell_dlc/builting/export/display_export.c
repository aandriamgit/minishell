/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:48:05 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/28 13:44:32 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void mini_display(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '=')
		{
			ft_putchar_p(tmp[i], 1);
			i++;
			ft_putchar_p('\"', 1);
			while (tmp[i])
			{
				ft_putchar_p(tmp[i], 1);
				i++;
			}
			ft_putchar_p('"', 1);
			ft_putchar_p('\n', 1);
			return ;
		}
		else
			ft_putchar_p(tmp[i], 1);
		i++;
	}
	printf("\n");
}

void display_export_list(t_list **list)
{
	t_list *tmp;
	
	tmp = *list;
	while (tmp)
	{
		mini_display(tmp->cmd);
		tmp = tmp->next;
	}
}
