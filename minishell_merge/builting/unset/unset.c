/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:18:27 by mravelon          #+#    #+#             */
/*   Updated: 2024/10/14 16:40:59 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int compare_param(char *parameter, char *str)
{
	int i;

	i = 0;
	while (parameter[i] && parameter[i] != '=')
	{
		if (parameter[i] != str[i])
			return(1);
		i++;
	}
	return (0);
}

int	check_by_list(t_list **env, char *str)
{
	t_list *tmp;
	t_list *prev;

	tmp = *env;
	prev = NULL;
	while (tmp)
	{
		if (compare_param(tmp->parameter, str) == 0)
		{
				if (prev)
				{
					prev->next = tmp->next;
					free(tmp);
				}
				else
				{
					prev = tmp;
					tmp = tmp->next;
					free(prev);
				}
			return (0);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}

int	unset(t_list **environement, char *str)
{
	int i;
	char **splited_str;

	i = 0;
	splited_str = ft_split(str, ' ');
	while (splited_str[i])
	{
		if (check_assignation(splited_str[i]) == 1)
		{
			printf("invalid parameter name\n");
			return(1);
		}
		check_by_list(environement, splited_str[i]);
		i++;
	}
	return (0);
}