/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:03:19 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/11 15:59:02 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_supremacy.h"

static char	*get_heredoc_nb(char *heredoc_dir)
{
	char	*res;
	char	*prev;
	char	*tmp;
	int		fd;
	int		nb;

	tmp = ft_strjoin_a(heredoc_dir, "/.log");
	fd = open(tmp, O_RDONLY);
	free(tmp);
	nb = 1;
	prev = get_next_line(fd);
	while (prev)
	{
		free(prev);
		prev = get_next_line(fd);
		if (prev)
			nb++;
	}
	res = ft_itoa_a(nb);
	close(fd);
	return (res);
}

static char	*init_lol(int *fd_heredoc, t_vars *vars)
{
	char	*heredoc_nb;
	char	*lol;
	char	*tmp;

	heredoc_nb = get_heredoc_nb(vars->heredoc_dir);
	tmp = ft_strjoin_a("/.", heredoc_nb);
	lol = ft_strjoin_a(vars->heredoc_dir, tmp);
	*fd_heredoc = open(lol, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	free(tmp);
	free(lol);
	return (heredoc_nb);
}

void	init_heredoc(t_vars *vars, char *eof)
{
	char	*input_heredoc;
	char	*heredoc_nb;
	int		fd_heredoc;

	heredoc_nb = init_lol(&fd_heredoc, vars);
	while (1)
	{
		input_heredoc = readline("> ");
		if (!input_heredoc || ft_strncmp_a(input_heredoc, eof) == 0)
		{
			if (!input_heredoc)
			{
				ft_putstr_fd_a("Minishell: warning: here-document ", 1);
				ft_putstr_fd_a("delimited end-of-file (wanted `", 1);
				ft_putstr_fd_a(eof, 1);
				ft_putstr_fd_a("\')\n", 1);
			}
			free(eof);
			close(fd_heredoc);
			free(heredoc_nb);
			return ;
		}
		ft_putstr_fd_a(input_heredoc, fd_heredoc);
		ft_putstr_fd_a("\n", fd_heredoc);
	}
}
