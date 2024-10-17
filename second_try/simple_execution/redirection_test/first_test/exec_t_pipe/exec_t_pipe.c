/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:51:58 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/17 14:17:46 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../first_test.h"

int	create_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		perror("create_pipe");
		return (-1);
	}
	return (0);
}

pid_t	create_child(t_command *cmd, int *pipe_fd, t_pipe *next)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("create_child");
		exit(1);
	}
	if (pid == 0)
	{
		if (!is_last(next))
			dup2(pipe_fd[1], STDOUT_FILENO);
		if (cmd->next)
			dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		handle_cmd(cmd);
	}
	return (pid);
}
