/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:27:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/20 10:17:52 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../first_test.h"

void	error_protocol(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	create_pipe(int *pipe_fd, t_pipe test_pipe)
{
	if (!test_pipe.prev)
		return ;
	if (!test_pipe.next)
		return ;
	if (pipe(pipe_fd) == -1)
		error_protocol("create pipe fail");
}

void	handle_cmd(t_pipe test_pipe, t_command *cmd, int input_fd,
		int output_fd)
{
	ft_putstr_fd("pourquoi ? what?\n", 1);
	if (test_pipe.prev && input_fd != 0)
	{
		ft_putstr_fd("pourquoi ?\n", 1);
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (test_pipe.next && output_fd != 1)
	{
		ft_putstr_fd("pourquoi ? ici ?\n", 1);
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
	ft_putstr_fd("pourquoi ? ok?\n", 1);
	handle_redir(cmd->redir);
	ft_execve_lol(cmd->cmd, cmd->args);
	exit(0);
}
