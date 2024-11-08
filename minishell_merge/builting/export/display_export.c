/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:48:05 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/08 15:29:16 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	mini_display(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '=')
		{
			printf("%c", tmp[i]);
			i++;
			printf("%c", '"');
			while (tmp[i])
			{
				printf("%c", tmp[i]);
				i++;
			}
			printf("%c\n", '"');
			return ;
		}
		else
			printf("%c", tmp[i]);
		i++;
	}
}

void	display_export_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		mini_display(tmp->parameter);
		tmp = tmp->next;
	}
}
