/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:02:31 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/01 16:19:55 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void	export_with_arg(t_list **env, char *arg)
{
	char **splited_arg;
	int i;

	i = 0;
	splited_arg = ft_split_p(arg, ' ');
	while (splited_arg[i])
	{
		if (check_list(env, splited_arg[i]) == 1)
			creat_chain_of_list(env, creat_bloc_of_list(splited_arg[i]));
		i++;
	}
}