/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:31:50 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/02 12:56:31 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../interpret/interpret.h"
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

static void	extra_print_heredoc(t_vars *vars, char **input_heredoc,
		int heredoc_type, int fd_heredoc)
{
	if (vars->exit_code_int == 130)
	{
		vars->save_heredoc = ft_strdup_a(*input_heredoc);
		ft_add_history(vars->save_heredoc, vars);
	}
	if (heredoc_type == 1)
		improved_expend(input_heredoc, vars->env, vars);
	ft_putstr_fd_a(*input_heredoc, fd_heredoc);
	ft_putstr_fd_a("\n", fd_heredoc);
	if (*input_heredoc)
	{
		free(*input_heredoc);
		*input_heredoc = NULL;
	}
}

static void	end_of_game(char *input_heredoc, char *eof, t_vars *vars)
{
	if (input_heredoc)
		free(input_heredoc);
	if (input_heredoc == NULL)
	{
		free(eof);
		vars->save_heredoc = ft_strdup_a("exit");
	}
	else
	{
		vars->save_heredoc = ft_strdup_a(input_heredoc);
		ft_add_history(vars->save_heredoc, vars);
	}
}

void	print_heredoc(t_vars *vars, char *eof, int heredoc_type, int fd_heredoc)
{
	char	*input_heredoc;

	while (1 && vars->exit_code_int != 130)
	{
		input_heredoc = readline("> ");
		if (!input_heredoc || ft_strncmp_a(input_heredoc, eof) == 0)
		{
			vars->exit_code_int = download_exit_code(vars);
			if (vars->exit_code_int == 130)
			{
				end_of_game(input_heredoc, eof, vars);
				return ;
			}
			extra(&input_heredoc, fd_heredoc, &eof);
			return ;
		}
		else
			vars->exit_code_int = download_exit_code(vars);
		extra_print_heredoc(vars, &input_heredoc, heredoc_type, fd_heredoc);
	}
	free(eof);
}
