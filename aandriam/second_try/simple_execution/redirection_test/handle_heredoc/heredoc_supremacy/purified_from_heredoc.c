/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purified_from_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:00:11 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/11 15:43:42 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../simple_execution.h"

static int	found_heredoc(t_redirection *redir)
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

static char	*getting_nb(char *heredoc_dir, int nb)
{
	char	*res;
	char	*nb_char;
	char	*tmp;
	int		fd;
	char	*log;

	nb_char = ft_itoa(nb);
	tmp = ft_strjoin(heredoc_dir, "/.");
	log = ft_strjoin(heredoc_dir, "/.log");
	res = ft_strjoin(tmp, nb_char);
	free(nb_char);
	free(tmp);
	fd = open(log, O_WRONLY | O_APPEND);
	ft_putstr_fd(".\n", fd);
	close(fd);
	free(log);
	return (res);
}

void	purified_from_heredoc(t_pipe **test_pipe, char *heredoc_dir, int nb)
{
	t_pipe			*voyager_one;
	t_redirection	*lol;

	voyager_one = *test_pipe;
	while (voyager_one)
	{
		if (found_heredoc(voyager_one->cmd->redir))
		{
			lol = voyager_one->cmd->redir;
			while (ft_strncmp("<<", lol->type) != 0)
			{
				lol = lol->next;
			}
			free(lol->type);
			lol->type = ft_strdup("<");
			free(lol->file);
			lol->file = getting_nb(heredoc_dir, nb);
			return ;
		}
		voyager_one = voyager_one->next;
	}
}
