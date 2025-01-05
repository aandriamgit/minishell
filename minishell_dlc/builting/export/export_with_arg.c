/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:02:31 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/05 18:40:32 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../utils/utils.h"
#include "../../parsing.h"

void	export_with_arg(t_list **env, char *arg)
{
	if (check_list(env, arg) == 1)
		creat_chain_of_list(env, creat_bloc_of_list(arg));
}
