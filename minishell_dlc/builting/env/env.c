/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:51:30 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 12:43:12 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

t_list	*duplicate_env(char **env)
{
	int		i;
	t_list	*environement;

	i = 0;
	environement = NULL;
	while (env[i])
	{
		creat_chain_of_list(&environement, creat_bloc_of_list(env[i]));
		i++;
	}
	return (environement);
}
