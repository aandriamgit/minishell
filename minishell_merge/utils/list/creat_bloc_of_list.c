/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_bloc_of_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:09:30 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/08 15:41:53 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_assignation(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '=') && (str[i + 1] != '\0'))
			return (1);
		i++;
	}
	return (0);
}

t_list	*creat_bloc_of_list(char *str)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->parameter = str;
	list->assignation = check_assignation(str);
	list->next = NULL;
	return (list);
}
