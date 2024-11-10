/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stderr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:46:36 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/10 16:07:47 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forge_of_commands.h"

void	init_stderr(t_stderr_a *stderr_a)
{
	int	fd;

	fd = open(stderr_a->dir, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	close(fd);
	fd = open(stderr_a->dir, O_WRONLY | O_CREAT | O_APPEND);
	stderr_a->fd = fd;
}
