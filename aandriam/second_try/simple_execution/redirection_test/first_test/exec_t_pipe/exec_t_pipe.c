/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:27:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/07 15:34:08 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../first_test.h"

void	ft_execve_lol(char *cmd, char **argv)
{
	char	*path;
	char	*mini_cmd;
	char	*tmp;

	mini_cmd = ft_strjoin("/", cmd);
	path = test_path(getenv("PATH"), mini_cmd);
	if (!path)
	{
		tmp = ft_strjoin(cmd, "\n");
		ft_perror("command not found", tmp);
	}
	else
		execve(path, argv, NULL);
}

void	handle_redir(t_redirection *redir)
{
	while (redir)
	{
		if (ft_strncmp(redir->type, "<") == 0)
			input_redir(redir->file);
		if (ft_strncmp(redir->type, ">") == 0)
			output_redir(redir->file);
		if (ft_strncmp(redir->type, ">>") == 0)
			append_redir(redir->file);
		redir = redir->next;
	}
}

int	is_built_ins(t_command *cmd)
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

void	built_ins(t_command *cmd)
{
	if (ft_strncmp(cmd->args[0], "echo") == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd->args[0], "cd") == 0)
		ft_cd(cmd);
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
	if (is_built_ins(cmd))
		built_ins(cmd);
	else
		ft_execve_lol(cmd->cmd, cmd->args);
}
