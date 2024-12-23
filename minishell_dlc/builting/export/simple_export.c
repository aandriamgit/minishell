/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:37:14 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/19 14:43:38 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"
#include "../../../minishell.h"

t_list   *duplicate_export(t_list *env)
{
	int i;
	t_list *export;
	t_list *tmp;

	i = 0;
	export = NULL;
	tmp = env;
	while (tmp)
	{
		creat_chain_of_list(&export, creat_bloc_of_list(tmp->cmd));
		tmp = tmp->next;
		i++;
	}
	return (export);
}

void	simple_export(t_list *env)
{
	t_list *export;

	export = duplicate_export(env);
	ordered_list(&export);
	display_export_list(&export);
	ft_free_t_list(&export);
}
