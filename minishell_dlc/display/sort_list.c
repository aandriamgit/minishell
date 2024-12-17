/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:13:02 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/01 12:30:52 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int compare(char *first, char *second)
{
	int i;
	
	i = 0;
	while (first[i] && second[i])
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	return (first[i] - second[i]);
}

t_list	*duplicate(t_list *list)
{
	t_list *copie;
	t_list *tmp;

	copie = NULL;
	tmp = list;
	while (tmp)
	{
		creat_chain_of_list(&copie, creat_bloc_of_list(tmp->cmd));
		tmp = tmp->next;
	}
	return(copie);
}

void	sort_list(t_list **list)
{
	t_list *tmp;
	char *c;
	int i;

	tmp = *list;
	c = NULL;
	i = 0;
	while (tmp && tmp->next)
	{
		if (compare(tmp->arg, tmp->next->arg) > 0)
		{
			c = ft_strdup_p(tmp->arg);
			tmp->arg = ft_strdup_p(tmp->next->arg);
			tmp->next->arg = ft_strdup_p(c);
			free(c);

			c = ft_strdup_p(tmp->parameter);
			tmp->parameter = ft_strdup_p(tmp->next->parameter);
			tmp->next->parameter = ft_strdup_p(c);
			free(c);

			/*c = ft_strdup_p(tmp->cmd);
			tmp->cmd = tmp->next->cmd;
			tmp->next->cmd = c;
			free(c);

			i = tmp->assignation;
			tmp->assignation = tmp->next->assignation;
			tmp->next->assignation = i;

			i = tmp->size_arg;
			tmp->size_arg = tmp->next->size_arg;
			tmp->next->size_arg = i;*/
			
			tmp = *list;
		}
		else
			tmp = tmp->next;
	}
}

/*void	sort_list(t_list **list)
{
	t_list *tmp;
	t_list *c;

	tmp = *list;
	c = NULL;
	while ((*list) && (*list)->next)
	{
		if (compare((*list)->arg,(*list)->next->arg) > 0)
		{
			c = (*list);
			(*list) = (*list)->next;
			(*list)->next = c;
			(*list) = tmp;
		}
		else
			(*list) = (*list)->next;
	}
	(*list) = tmp;
}*/
