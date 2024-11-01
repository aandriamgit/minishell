/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:02 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/01 13:29:55 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_test.h"

t_command	*gen_cmd(char *cmd, char **big_param, void *redir, void *next)
{
	t_command	*cmd_res;

	cmd_res = malloc(sizeof(t_command));
	if (!cmd_res)
		return (NULL);
	cmd_res->cmd = cmd;
	cmd_res->args = big_param;
	cmd_res->next = next;
	cmd_res->redir = redir;
	return (cmd_res);
}

t_redirection	*gen_redir(char *type, char *file, void *next)
{
	t_redirection	*redir_res;

	redir_res = malloc(sizeof(t_redirection));
	if (!redir_res)
		return (NULL);
	redir_res->next = next;
	redir_res->file = file;
	redir_res->type = type;
	return (redir_res);
}

void	exec_t_pipe(t_pipe *test_pipe)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		input_fd;

	input_fd = 0;
	while (test_pipe)
	{
		if (test_pipe->prev || test_pipe->next)
			if (pipe(pipe_fd) == -1)
				error_protocol("create pipe fail");
		pid = fork();
		if (pid == 0)
			handle_cmd(*test_pipe, test_pipe->cmd, input_fd, pipe_fd[1]);
		else if (pid < 0)
			error_protocol("fork fail");
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

void	free_redir(t_redirection *redir)
{
	t_redirection	*tmp;

	while (redir)
	{
		tmp = redir;
		free(redir->type);
		free(redir->file);
		redir = redir->next;
		free(tmp);
	}
}

void	free_t_pipe(t_pipe *test_pipe)
{
	while (test_pipe)
	{
		free_redir(test_pipe->cmd->redir);
		ft_free_all(&test_pipe->cmd->args);
		free(test_pipe->cmd);
		test_pipe = test_pipe->next;
	}
}
