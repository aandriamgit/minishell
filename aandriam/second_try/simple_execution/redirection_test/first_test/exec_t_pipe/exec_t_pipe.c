/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:27:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/20 11:03:48 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../first_test.h"

void	error_protocol(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	handle_cmd(t_pipe test_pipe, t_command *cmd, int input_fd,
		int output_fd)
{
	if (test_pipe.prev && input_fd != 0)
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
	exit(0);
}
