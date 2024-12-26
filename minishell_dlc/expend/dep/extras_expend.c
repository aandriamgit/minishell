/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_expend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:08:46 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/26 14:17:36 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dep.h"

char	*gen_exit_code(t_vars	*vars)
{
	char	*res;
	char	*tmp;

	tmp = ft_itoa_a(vars->exit_code_int);
	res = ft_strjoin_a("?=", tmp);
	free(tmp);
	return (res);
}
