/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_supremacy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:49:16 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/02 13:15:46 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../simple_execution.h"

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

void	init_heredoc(t_vars *vars, char *eof)
{
	char	*input_heredoc;
	int		fd_heredoc;

	fd_heredoc = open(vars->heredoc_dir, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	while (1)
	{
		input_heredoc = readline(">");
		if (!input_heredoc || ft_strncmp(input_heredoc, eof) == 0)
		{
			if (!input_heredoc)
			{
				ft_putstr_fd("Minishell: warning: here-document ", 1);
				ft_putstr_fd("delimited end-of-file (wanted `", 1);
				ft_putstr_fd(eof, 1);
				ft_putstr_fd("\')\n", 1);
			}
			free(eof);
			close(fd_heredoc);
			return ;
		}
		ft_putstr_fd(input_heredoc, fd_heredoc);
		ft_putstr_fd("\n", fd_heredoc);
	}
}

void	purified_from_heredoc(t_pipe **test_pipe, char *heredoc_dir)
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
			lol->file = ft_strdup(heredoc_dir);
		}
		voyager_one = voyager_one->next;
	}
}
