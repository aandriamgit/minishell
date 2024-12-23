/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:31:50 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/23 14:32:38 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_dlc/parsing.h"
#include "heredoc_supremacy.h"

static void	extra(char **input_heredoc, int fd_heredoc, char **eof)
{
	if (*input_heredoc == NULL)
	{
		ft_putstr_fd_a("Minishell: warning: here-document ", 1);
		ft_putstr_fd_a("delimited end-of-file (wanted `", 1);
		ft_putstr_fd_a(*eof, 1);
		ft_putstr_fd_a("\')\n", 1);
	}
	free(*eof);
	close(fd_heredoc);
	if (*input_heredoc != NULL)
	{
		free(*input_heredoc);
		*input_heredoc = NULL;
	}
}

static void	magic_expend(char **input_heredoc, t_vars *vars)
{
	modify_str(input_heredoc, vars->env);
	ft_putstr_fd_a("work still on progress\n", 1);
}

static void	expend_them(t_vars *vars, char *eof, int fd_heredoc)
{
	char	*input_heredoc;

	while (1)
	{
		input_heredoc = readline("> ");
		if (!input_heredoc || ft_strncmp_a(input_heredoc, eof) == 0)
		{
			extra(&input_heredoc, fd_heredoc, &eof);
			return ;
		}
		magic_expend(&input_heredoc, vars);
		ft_putstr_fd_a(input_heredoc, fd_heredoc);
		ft_putstr_fd_a("\n", fd_heredoc);
		if (input_heredoc)
		{
			free(input_heredoc);
			input_heredoc = NULL;
		}
	}
}

static void	dont_expend_them(t_vars *vars, char *eof, int fd_heredoc)
{
	char	*input_heredoc;

	(void)vars;
	while (1)
	{
		input_heredoc = readline("> ");
		if (!input_heredoc || ft_strncmp_a(input_heredoc, eof) == 0)
		{
			extra(&input_heredoc, fd_heredoc, &eof);
			return ;
		}
		ft_putstr_fd_a(input_heredoc, fd_heredoc);
		ft_putstr_fd_a("\n", fd_heredoc);
		if (input_heredoc)
		{
			free(input_heredoc);
			input_heredoc = NULL;
		}
	}
}

void	print_heredoc(t_vars *vars, char *eof, int heredoc_type, int fd_heredoc)
{
	if (heredoc_type == 1)
		expend_them(vars, eof, fd_heredoc);
	else
		dont_expend_them(vars, eof, fd_heredoc);
}
