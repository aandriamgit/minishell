/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:51:58 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/18 11:57:44 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_t_pipe.h"

// {
// 	if (pipe(pipe_fd) == -1)
// 	{
// 		perror("create_pipe");
// 		return (-1);
// 	}
// 	return (0);
// }
//
// pid_t	create_child(t_command *cmd, int *pipe_fd, t_pipe *next)
// {
// 	pid_t	pid;
//
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("create_child");
// 		exit(1);
// 	}
// 	if (pid == 0)
// 	{
// 		if (!is_last(next))
// 			dup2(pipe_fd[1], STDOUT_FILENO);
// 		if (cmd->next)
// 			dup2(pipe_fd[0], STDIN_FILENO);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		handle_cmd(cmd);
// 	}
// 	return (pid);
// }

pid_t	first_in_line(t_command *cmd)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	change_stdout(pipe_fd);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
	}
	return (pid);
}
