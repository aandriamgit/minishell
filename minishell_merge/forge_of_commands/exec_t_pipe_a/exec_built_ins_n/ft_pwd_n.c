/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:04:54 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/15 13:09:49 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_built_ins_n.h"

void	ft_pwd_n(t_command_a *cmd, t_vars *vars)
{
	char	buffer[1024];
	int		save_fd;

	(void)cmd;
	save_fd = dup(STDOUT_FILENO);
	getcwd(buffer, 1024);
	handle_redir(cmd->redir, vars);
	ft_putstr_fd_a(buffer, STDOUT_FILENO);
	ft_putstr_fd_a("\n", STDOUT_FILENO);
	dup2(save_fd, STDOUT_FILENO);
	close(save_fd);
}
