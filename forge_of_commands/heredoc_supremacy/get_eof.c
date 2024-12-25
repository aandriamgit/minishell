/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_eof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:01:08 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:30:57 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_supremacy.h"

static int	found_heredoc(t_redirection_a *redir)
{
	t_redirection_a	*voyager_one;

	voyager_one = redir;
	while (voyager_one)
	{
		if (ft_strncmp_a(voyager_one->type, "<<") == 0)
			return (1);
		voyager_one = voyager_one->next;
	}
	return (0);
}

char	*get_eof(t_pipe_a *test_pipe)
{
	char			*res;
	t_redirection_a	*lol;
	t_pipe_a		*voyager_one;

	voyager_one = test_pipe;
	res = NULL;
	while (voyager_one)
	{
		if (found_heredoc(voyager_one->cmd->redir))
		{
			lol = voyager_one->cmd->redir;
			while (ft_strncmp_a("<<", lol->type) != 0)
			{
				lol = lol->next;
			}
			res = ft_strdup_a(lol->file);
			return (res);
		}
		voyager_one = voyager_one->next;
	}
	return (res);
}
