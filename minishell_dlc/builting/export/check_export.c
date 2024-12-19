/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:29:35 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/19 17:31:35 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

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

int check_exp(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char *bloc(char *str)
{
	int start;
	int i;

	i = 0;
	start = 0;
	while(str[i] != '=')
		i++;
	start = i + 1;
	if (str[start] == '\0')
		return (NULL);
	else
	{
		i++;
		while (str[i])
			i++;
	}
	return (ft_substr_p(start, i - 1, str));
}

int check_list(t_list **env, char *str)
{
	t_list *tmp;
	t_list *prev;
	t_list *c;

	tmp = *env;
	c = *env;
	while (tmp)
	{
		if (compare_content(tmp->arg, str) == 1)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		else 
		{
			if (check_exp(str) == 1)
			{
				if (tmp != NULL)
				{
					unset_p(env, tmp->arg);
					creat_chain_of_list(env, creat_bloc_of_list(str));
				}
			}
			tmp->assignation = check_assignation(str);
			return (0);
		}
	}
	return (1);
}
