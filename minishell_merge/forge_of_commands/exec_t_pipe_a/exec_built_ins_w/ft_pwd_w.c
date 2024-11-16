/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:54:42 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/15 13:02:56 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_built_ins_w.h"

void	ft_pwd_w(t_command_a *cmd, t_vars *vars)
{
	char	buffer[1024];

	(void)cmd;
	getcwd(buffer, 1024);
	ft_putstr_fd_a(buffer, STDOUT_FILENO);
	ft_putstr_fd_a("\n", STDOUT_FILENO);
	ft_perror_row(NULL, NULL, vars);
}
