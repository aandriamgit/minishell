/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:02 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/17 14:24:08 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_test.h"
#include <time.h>

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
	int		status;
	pid_t	pid;
	t_pipe	*voyager_one;

	voyager_one = test_pipe;
	while (voyager_one)
	{
		if (voyager_one->next)
			if (create_pipe(pipe_fd) == -1)
				exit(1);
		pid = create_child(test_pipe->cmd, pipe_fd, test_pipe->next);
		if (voyager_one->next)
			close(pipe_fd[1]);
		voyager_one = voyager_one->next;
	}
	while (wait(NULL) > 0)
	{
	}
}
