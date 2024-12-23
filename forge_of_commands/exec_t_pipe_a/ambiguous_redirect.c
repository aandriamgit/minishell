/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:24:07 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/23 18:21:46 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_t_pipe_a.h"

int	ambiguous_redirect(char **file, t_vars *vars, char **file_dup)
{
	char	*tmp_file;

	tmp_file = *file;
	if (tmp_file[0] == '$')
	{
	}
	return (0);
}
