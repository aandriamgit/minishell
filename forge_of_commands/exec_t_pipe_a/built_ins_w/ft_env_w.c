/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:07:50 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/16 16:56:13 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

void	ft_env_w(t_command_a *cmd, t_vars *vars)
{
	(void)cmd;
	(void)vars;
	ft_putstr_fd_a("work still on progress\n", 1);
	ft_perror_exit(NULL, NULL, vars, 0);
}
