/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:29:35 by mravelon          #+#    #+#             */
/*   Updated: 2024/10/14 12:58:50 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int compare_content(char *parameter, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] != parameter[i])
			return (1);
		i++;
	}
	return (0);
}


int check_list(t_list **env, char *str)
{
	t_list *tmp;

	tmp = *env;
	while (tmp)
	{
		if (compare_content(tmp->parameter, str) == 1)
			tmp = tmp->next;
		else 
		{
			tmp->parameter = str;
			tmp->assignation = check_assignation(str);
			return (0);
		}
	}
	return (1);
}
