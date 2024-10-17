/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:55:31 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/11 11:06:16 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static void	exec_cmd(t_command *cmd, t_vars *vars)
{
	char	*path;
	char	*cmd_o;

	cmd_o = ft_strjoin("/", cmd->args[0]);
	path = test(getenv("PATH"), cmd_o);
	fork_exec_nopipe(path, cmd->args, vars);
	free(path);
	free_res(&cmd->args);
}

static void	fork_them(int *pipefd, char **output, t_pipe v_one, t_vars *vars)
{
	char	buffer[1024];
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
		exec_cmd(v_one.redirection->cmd, vars);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pipefd[1]);
		read(pipefd[0], buffer, 1024);
		close(pipefd[0]);
		wait(NULL);
	}
	*output = ft_strdup(buffer);
}

char	*get_output(t_pipe *v_one, t_vars *vars)
{
	char	*output;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	fork_them(pipefd, &output, *v_one, vars);
	return (output);
}

void	use_as_input(char **buff, t_pipe *v_one)
{
	(void)v_one;
	free(*buff);
}
