/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_bloc_of_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:09:30 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/29 16:54:07 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int check_assignation(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '=') && (str[i + 1] != '\0'))
			return (1);
		i++;
	}
	return (0);
}

char *creat_arg(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (ft_substr_p(0, i - 1, str));
}

char *creat_param(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (ft_substr_p(i + 1, ft_strlen_p(str) - 1, str));
}

t_list	*creat_bloc_of_list(char *str)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->cmd = str;
	list->arg = creat_arg(str);
	list->assignation = check_assignation(str);
	if (list->assignation == 1)
	{
		list->parameter = creat_param(str);
		list->size_arg = ft_strlen_p(list->parameter);
	}
	else
	{
		list->parameter = NULL;
		list->size_arg = 0;
	}
	list->next = NULL;
	return (list);
}
