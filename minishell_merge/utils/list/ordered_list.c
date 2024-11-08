/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:16:36 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/08 15:41:06 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ordered_list(t_list **list)
{
	t_list	*tmp;
	char	*stock;
	int		c;

	stock = NULL;
	tmp = *list;
	c = 0;
	while (tmp && tmp->next)
	{
		c = ft_strcmp(tmp->parameter, tmp->next->parameter);
		if (c > 0)
		{
			stock = tmp->parameter;
			tmp->parameter = tmp->next->parameter;
			tmp->next->parameter = stock;
			tmp = *list;
		}
		else
			tmp = tmp->next;
	}
}
