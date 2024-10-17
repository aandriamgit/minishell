/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:51:30 by mravelon          #+#    #+#             */
/*   Updated: 2024/10/17 14:46:21 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void display_env_list(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		if(tmp->assignation == 1)
			printf("%s\n", tmp->parameter);
		tmp = tmp->next;
	}
}

t_list   *duplicate_env(char **env)
{
	int i;
	t_list *environement;

	i = 0;
	environement = NULL;
	while (env[i])
	{
		creat_chain_of_list(&environement, creat_bloc_of_list(env[i]));
		i++;
	}
	return (environement);
}
