/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:21:15 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/02 17:26:03 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_test.h"

void	finish_errors(char **tmp, char **res)
{
	char	*tmp_o;
	char	*res_o;
	int		fd;

	tmp_o = *tmp;
	res_o = *res;
	free(tmp_o);
	fd = open(res_o, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	free(res_o);
	close(fd);
}
