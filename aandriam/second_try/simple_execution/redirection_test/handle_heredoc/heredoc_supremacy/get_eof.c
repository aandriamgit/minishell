/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_eof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:01:08 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/04 10:01:30 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../simple_execution.h"

int	found_heredoc(t_redirection *redir)
{
	t_redirection	*voyager_one;

	voyager_one = redir;
	while (voyager_one)
	{
		if (ft_strncmp(voyager_one->type, "<<") == 0)
			return (1);
		voyager_one = voyager_one->next;
	}
	return (0);
}

char	*get_eof(t_pipe *test_pipe)
{
	char			*res;
	t_redirection	*lol;
	t_pipe			*voyager_one;

	voyager_one = test_pipe;
	res = NULL;
	while (voyager_one)
	{
		if (found_heredoc(voyager_one->cmd->redir))
		{
			lol = voyager_one->cmd->redir;
			while (ft_strncmp("<<", lol->type) != 0)
			{
				lol = lol->next;
			}
			res = ft_strdup(lol->file);
		}
		voyager_one = voyager_one->next;
	}
	return (res);
}
