/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:18:27 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 12:35:13 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"
#include "../../../minishell.h"
#include <stdio.h>

int	compare_param(char *parameter, char *str)
{
	int	i;

	i = 0;
	while (parameter[i] && parameter[i] != '=')
	{
		if (parameter[i] != str[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_by_list(t_list **env, char *str, t_list *tmp, t_list *prev)
{
	tmp = *env;
	while (tmp)
	{
		if (compare_param(tmp->arg, str) == 0)
		{
			if (prev != NULL)
			{
				prev->next = tmp->next;
				free_node_list(&tmp);
			}
			else
			{
				prev = tmp;
				tmp = tmp->next;
				*env = tmp;
				free_node_list(&prev);
			}
			return (0);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}

int	unset_p(t_list **environement, char *str)
{
	int		i;
	char	**splited_str;
	t_list	*tmp;
	t_list	*prev;

	i = 0;
	tmp = NULL;
	prev = NULL;
	splited_str = ft_split_p(str, ' ');
	while (splited_str[i])
	{
		if (check_assignation(splited_str[i]) == 1)
		{
			printf("invalid parameter name\n");
			return (1);
		}
		check_by_list(environement, splited_str[i], tmp, prev);
		i++;
	}
	ft_free_tab(&splited_str);
	return (0);
}
