/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:18:27 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/08 15:48:31 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

void	extra(t_list **tmp, t_list **prev)
{
	t_list	*previous;
	t_list	*tmp_o;

	previous = *prev;
	tmp_o = *tmp;
	if (previous)
	{
		previous->next = tmp_o->next;
		free(tmp_o);
	}
	else
	{
		previous = tmp_o;
		tmp_o = tmp_o->next;
		free(previous);
	}
}

int	check_by_list(t_list **env, char *str)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *env;
	prev = NULL;
	while (tmp)
	{
		if (compare_param(tmp->parameter, str) == 0)
		{
			extra(&tmp, &prev);
			return (0);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}

int	unset(t_list **environement, char *str)
{
	int		i;
	char	**splited_str;

	i = 0;
	splited_str = ft_split(str, ' ');
	while (splited_str[i])
	{
		if (check_assignation(splited_str[i]) == 1)
		{
			printf("invalid parameter name\n");
			return (1);
		}
		check_by_list(environement, splited_str[i]);
		i++;
	}
	return (0);
}
