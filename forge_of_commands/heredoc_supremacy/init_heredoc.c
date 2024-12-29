/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:03:19 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/29 13:52:07 by aandriam         ###   ########.fr       */
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

static char	*init_heredoc_nb(int *fd_heredoc, t_vars *vars)
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

static int	get_heredoc_type(char *eof)
{
	int	i;

	i = 0;
	if (eof)
	{
		while (eof[i])
		{
			if (eof[i] == '\'' || eof[i] == '\"')
			{
				if (i == 1)
					return (3);
				else
					return (2);
			}
			i++;
		}
	}
	return (1);
}

static void	nice_eof(char **eof, int heredoc_type)
{
	char	*new;

	if (heredoc_type == 3)
	{
		new = ft_substr_a(*eof, 1, ft_strlen_a(*eof));
		rm_quote(&new);
		free(*eof);
		*eof = new;
	}
	else if (heredoc_type == 2)
		rm_quote(eof);
}

void	init_heredoc(t_vars *vars, char *eof)
{
	char	*heredoc_nb;
	int		fd_heredoc;
	int		heredoc_type;

	if (eof == NULL)
		eof = ft_strdup_a("\n");
	heredoc_nb = init_heredoc_nb(&fd_heredoc, vars);
	heredoc_type = get_heredoc_type(eof);
	nice_eof(&eof, heredoc_type);
	free(heredoc_nb);
	print_heredoc(vars, eof, heredoc_type, fd_heredoc);
}
