/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:29:03 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/17 17:13:13 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../utils/utils.h"

t_pipe	*gen_pipe(char **str)
{
	char **split;
	int i;
	t_pipe *p;

	i = 0;
	p = NULL;
	split = split_pipe((*str), '|');
	while (split[i])
	{
		creat_chain_of_pipe(&p, creat_bloc_pipe(&split[i]));
		i++;
	}
	ft_free_tab(&split);
	free(*str);
	(*str) = NULL;
	return (p);
}
