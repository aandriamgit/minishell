/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:17:43 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/08 11:01:46 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../first_test.h"

static int	is_built_ins_n(t_command *cmd)
{
	if (ft_strncmp(cmd->args[0], "echo") == 0)
		return (1);
	else if (ft_strncmp(cmd->args[0], "cd") == 0)
		return (1);
	else if (ft_strncmp(cmd->args[0], "pwd") == 0)
		return (1);
	else if (ft_strncmp(cmd->args[0], "export") == 0)
		return (1);
	else if (ft_strncmp(cmd->args[0], "unset") == 0)
		return (1);
	else if (ft_strncmp(cmd->args[0], "env") == 0)
		return (1);
	else if (ft_strncmp(cmd->args[0], "exit") == 0)
		return (1);
	return (0);
}

static void	built_ins_n(t_command *cmd)
{
	if (ft_strncmp(cmd->args[0], "echo") == 0)
		ft_echo_chill(cmd);
	else if (ft_strncmp(cmd->args[0], "cd") == 0)
		ft_cd_chill(cmd);
	// else if (ft_strncmp(cmd->args[0], "pwd") == 0)
	// 	ft_pwd(cmd);
	// else if (ft_strncmp(cmd->args[0], "export") == 0)
	// 	ft_export(cmd);
	// else if (ft_strncmp(cmd->args[0], "unset") == 0)
	// 	ft_unset(cmd);
	// else if (ft_strncmp(cmd->args[0], "env") == 0)
	// 	ft_env(cmd);
	// else
	// 	ft_exit(cmd);
}

void	no_pipe(t_pipe *test_pipe)
{
	pid_t	pid;

	handle_redir(test_pipe->cmd->redir);
	if (is_built_ins_n(test_pipe->cmd))
		built_ins_n(test_pipe->cmd);
	else
	{
		pid = fork();
		if (pid == 0)
			ft_execve_lol(test_pipe->cmd->cmd, test_pipe->cmd->args);
		else if (pid < 0)
			ft_perror("fork error", NULL);
		else
			wait(NULL);
	}
}

void	w_pipe(t_pipe *test_pipe)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		input_fd;

	input_fd = 0;
	while (test_pipe)
	{
		if (test_pipe->prev || test_pipe->next)
			if (pipe(pipe_fd) == -1)
				ft_perror("pipe error", NULL);
		pid = fork();
		if (pid == 0)
			handle_cmd(*test_pipe, test_pipe->cmd, input_fd, pipe_fd[1]);
		else if (pid < 0)
			ft_perror("fork error", NULL);
		if (test_pipe->next)
			close(pipe_fd[1]);
		if (input_fd != 0)
			close(input_fd);
		input_fd = pipe_fd[0];
		test_pipe = test_pipe->next;
	}
	while (wait(NULL) > 0)
		;
}
