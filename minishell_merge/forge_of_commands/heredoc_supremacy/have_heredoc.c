/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:26:59 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/11 15:28:32 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_supremacy.h"

static int	found_in_cmd(t_command_a *cmd)
{
	t_redirection_a	*voyager_two;

	voyager_two = cmd->redir;
	while (voyager_two)
	{
		if (ft_strncmp_a("<<", voyager_two->type) == 0)
			return (1);
		voyager_two = voyager_two->next;
	}
	return (0);
}

int	have_heredoc(t_pipe_a *test_pipe)
{
	t_pipe_a	*voyager_one;

	voyager_one = test_pipe;
	while (voyager_one)
	{
		if (found_in_cmd(voyager_one->cmd))
			return (1);
		voyager_one = voyager_one->next;
	}
	return (0);
}
