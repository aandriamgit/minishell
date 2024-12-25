/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:37:14 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/25 15:38:52 by mravelon         ###   ########.fr       */
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

void check_minimum(t_list *env_cp, char *str)
{
	t_list *tmp;
	char *min;

	min = NULL;
	tmp = env_cp;
	while (tmp && tmp->next)
	{
		if ((min == NULL || (min != NULL && ft_strncmp_a(min, tmp->cmd) > 0))  && (ft_strncmp_a(tmp->cmd, str) > 0))
		{
			min = tmp->cmd;
		}
		tmp = tmp->next;
	}
	if (min != NULL)
	{
		printf("declare_x %s\n", min);
		check_minimum(env_cp, min);
	}
}

void	simple_export(t_list *env_cp)
{
	check_minimum(env_cp, "");
}
