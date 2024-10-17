/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:08:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/17 14:32:22 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../first_test.h"

int	is_last(t_pipe *next)
{
	if (!next)
		return (0);
	return (1);
}

void	handle_redir(t_redirection *redir)
{
	(void)redir;
}

void	handle_cmd(t_command *cmd)
{
	if (cmd->redir)
		handle_redir(cmd->redir);
}
