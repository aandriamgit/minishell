/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purify_from_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:00:11 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/11 15:46:32 by aandriam         ###   ########.fr       */
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

static char	*getting_nb(char *heredoc_dir, int nb)
{
	char	*res;
	char	*nb_char;
	char	*tmp;
	int		fd;
	char	*log;

	nb_char = ft_itoa_a(nb);
	tmp = ft_strjoin_a(heredoc_dir, "/.");
	log = ft_strjoin_a(heredoc_dir, "/.log");
	res = ft_strjoin_a(tmp, nb_char);
	free(nb_char);
	free(tmp);
	fd = open(log, O_WRONLY | O_APPEND);
	ft_putstr_fd_a(".\n", fd);
	close(fd);
	free(log);
	return (res);
}

void	purify_from_heredoc(t_pipe_a **test_pipe, char *heredoc_dir, int nb)
{
	t_pipe_a		*voyager_one;
	t_redirection_a	*lol;

	voyager_one = *test_pipe;
	while (voyager_one)
	{
		if (found_heredoc(voyager_one->cmd->redir))
		{
			lol = voyager_one->cmd->redir;
			while (ft_strncmp_a("<<", lol->type) != 0)
			{
				lol = lol->next;
			}
			free(lol->type);
			lol->type = ft_strdup_a("<");
			free(lol->file);
			lol->file = getting_nb(heredoc_dir, nb);
			return ;
		}
		voyager_one = voyager_one->next;
	}
}
