/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:27:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/19 17:54:26 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../first_test.h"

void	error_protocol(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	create_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
		error_protocol("create pipe fail");
}

void	ft_execve_lol(char *cmd, char **args)
{
	char	*path;
	char	*mini_cmd;

	mini_cmd = ft_strjoin("/", cmd);
	path = test(getenv("PATH"), mini_cmd);
}

void	exec_cmd(t_command *cmd, int input_fd, int output_fd)
{
	if (input_fd != 0)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (output_fd != 1)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
	ft_execve_lol(cmd->cmd, cmd->args);
}