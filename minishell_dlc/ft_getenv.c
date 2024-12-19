/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:25:01 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/19 17:31:11 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../minishell.h"

char *ft_getenv(char *str, t_list *env)
{
	t_list *tmp;

	tmp = env;
	if (tmp != NULL)
	{
		while (tmp)
		{
			if (ft_strncmp_a(str, tmp->arg) == 0)
				return (ft_strdup_a(tmp->parameter));
			else
				tmp = tmp->next;
		}
	}
	return (NULL);
}
