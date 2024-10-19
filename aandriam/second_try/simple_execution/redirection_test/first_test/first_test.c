/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:02 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/19 16:58:57 by aandriam         ###   ########.fr       */
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
	int		status;
	int		pipe_fd[2];
	pid_t	pid;
	pid_t	wpid;
	int		input_fd;

	input_fd = 0;
	while (test_pipe)
	{
		create_pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
			exec_cmd(test_pipe->cmd, input_fd, pipe_fd[1]);
		else if (pid < 0)
			error_protocol("fork fail");
		close(pipe_fd[1]);
		input_fd = pipe_fd[0];
		test_pipe = test_pipe->next;
	}
	wpid = waitpid(pid, &status, WUNTRACED);
	while (wpid > 0 && (!WIFEXITED(status) && WIFSIGNALED(status)))
		wpid = waitpid(pid, &status, WUNTRACED);
}
