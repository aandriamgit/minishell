/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:59:07 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/20 14:53:04 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

void	ft_pwd_w(t_command_a *cmd, t_vars *vars)
{
	char	buffer[1024];

	if (cmd->args[1] && cmd->args[1][0] == '-')
		ft_perror_exit(cmd->args[1], "invalid option\n", vars, 1);
	else
	{
		if (getcwd(buffer, 1024))
		{
			ft_putstr_fd_a(buffer, STDOUT_FILENO);
			ft_putstr_fd_a("\n", STDOUT_FILENO);
		}
	}
	ft_perror_exit(NULL, NULL, vars, 0);
}
