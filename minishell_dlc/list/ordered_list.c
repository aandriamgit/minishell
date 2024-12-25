/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:16:36 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/19 14:38:14 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include "../../minishell.h"

void	ordered_list(t_list **list)
{
	t_list	*tmp;
	char	*stock;
	int c;

	stock = NULL;
	tmp = *list;
	c = 0;
	while (tmp && tmp->next)
	{
		c = ft_strncmp_a(tmp->arg, tmp->next->arg);
		if (c > 0)
		{
			stock = tmp->arg;
			tmp->arg = tmp->next->arg;
			tmp->next->arg = stock;
			stock = tmp->parameter;
			tmp->parameter = tmp->next->parameter;
			tmp->next->parameter = stock;
			tmp = *list;
		}
		else
			tmp = tmp->next;
	}
}
