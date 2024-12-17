/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:45:05 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/01 16:25:33 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	free_list(t_list **list)
{
	t_list *tmp;

	tmp = *list;

	while (tmp)
	{
		free((tmp)->arg);
		free((tmp)->cmd);
		free((tmp)->parameter);
		tmp = tmp->next;
	}
	free(*list);
}

void	display_list_p(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		ft_putstr_p(tmp->arg, 1);
		ft_putchar_p('=', 1);
		ft_putstr_p(tmp->parameter, 1);
		ft_putchar_p('\n', 1);
		tmp = tmp->next;
	}
}

void	display_env_p(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->assignation == 1)
		{
			ft_putstr_p(tmp->arg, 1);
			ft_putchar_p('=', 1);
			ft_putstr_p(tmp->parameter, 1);
			ft_putchar_p('\n', 1);
		}
		tmp = tmp->next;
	}
}

void	display_export_p(t_list *list)
{
	t_list *exp_list;
	t_list *tmp;

	tmp = NULL;
	exp_list = NULL;
	exp_list = duplicate(list);
	sort_list(&exp_list);
	tmp = exp_list;
	while (tmp)
	{
		if (tmp->assignation == 1)
		{
			ft_putstr_p(tmp->arg, 1);
			ft_putchar_p('=', 1);
			ft_putchar_p('\"', 1);
			ft_putstr_p(tmp->parameter, 1);
			ft_putchar_p('\"', 1);
			ft_putchar_p('\n', 1);
		}
		else
		{
			ft_putstr_p(tmp->arg, 1);
			ft_putchar_p('\n', 1);
		}
		tmp = tmp->next;
	}
	free(exp_list);
//	free_list(&exp_list);
}
