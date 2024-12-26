/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:02:31 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/21 17:51:41 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"
#include "../../../utils/utils.h"

void	export_with_arg(t_list **env, char *arg)
{
	char **splited_arg;
	int i;

	i = 0;
	splited_arg = ft_split_na(arg);
	while (splited_arg[i])
	{
		if (check_list(env, splited_arg[i]) == 1)
		{
			rm_quote(&splited_arg[i]);
			creat_chain_of_list(env, creat_bloc_of_list(splited_arg[i]));
		}
		i++;
	}
	ft_free_tab(&splited_arg);
}
