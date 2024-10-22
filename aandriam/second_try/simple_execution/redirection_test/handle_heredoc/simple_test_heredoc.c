/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:04:06 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/22 18:39:09 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../simple_execution.h"

int	found_in_cmd(t_command *cmd)
{
	t_redirection	*voyager_two;

	voyager_two = cmd->redir;
	while (voyager_two)
	{
		if (ft_strncmp("<<", voyager_two->type) == 0)
			return (1);
		voyager_two = voyager_two->next;
	}
	return (0);
}

int	have_heredoc(t_pipe *test_pipe)
{
	t_pipe	*voyager_one;

	voyager_one = test_pipe;
	while (voyager_one)
	{
		if (found_in_cmd(voyager_one->cmd))
			return (1);
		voyager_one = voyager_one->next;
	}
	return (0);
}

void	heredoc_supremacy(t_pipe *test_pipe, t_vars *vars)
{
	int		fd_heredoc;
	char	*eof;

	while (have_heredoc(test_pipe))
	{
		if (access(vars->log_dir, F_OK) == 0)
		{
			fd_heredoc = open(vars->heredoc_dir, O_WRONLY | O_TRUNC | O_CREAT,
					0755);
			close(fd_heredoc);
		}
		else
			perror("please dont mess with the minishell_log\n");
		eof = get_eof(test_pipe);
		init_heredoc(vars, eof);
		purified_from_heredoc(&test_pipe, vars->heredoc_dir);
	}
	exec_t_pipe(test_pipe);
}
