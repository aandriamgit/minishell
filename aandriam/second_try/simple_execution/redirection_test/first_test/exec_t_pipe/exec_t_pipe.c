/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:27:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/22 16:30:36 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../first_test.h"

void	ft_execve_lol(char *cmd, char **argv)
{
	char	*path;
	char	*mini_cmd;

	mini_cmd = ft_strjoin("/", cmd);
	path = test_path(getenv("PATH"), mini_cmd);
	if (!path)
	{
		ft_putstr_fd("error : command not found: ", 1);
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("\n", 1);
		return ;
	}
	else
		execve(path, argv, NULL);
}

void	error_protocol(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	handle_redir(t_redirection *redir)
{
	while (redir)
	{
		if (ft_strncmp(redir->type, "<") == 0)
			input_redir(redir->file);
		if (ft_strncmp(redir->type, ">") == 0)
			output_redir(redir->file);
		if (ft_strncmp(redir->type, ">>") == 0)
			append_redir(redir->file);
		redir = redir->next;
	}
}

void	handle_cmd(t_pipe test_pipe, t_command *cmd, int input_fd,
		int output_fd)
{
	if ((test_pipe.prev && input_fd != 0))
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (test_pipe.next && output_fd != 1)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
	handle_redir(cmd->redir);
	ft_execve_lol(cmd->cmd, cmd->args);
}
