/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:51:08 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/15 12:28:27 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_t_pipe_a.h"

static void	input_redir_t(char *file, t_vars *vars)
{
	int			fd;
	struct stat	file_stat;

	if (access(file, F_OK) == -1)
		ft_perror_row(file, "no such file or directory\n", vars);
	else if (access(file, R_OK) == -1)
		ft_perror_row(file, "permision denied\n", vars);
	else if (stat(file, &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
		ft_perror_row(file, "is a directory\n", vars);
	else
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_perror_row(NULL, "error while creating the file\n", vars);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

static void	output_redir_t(char *file, t_vars *vars)
{
	int			fd;
	char		*dir_file;
	struct stat	file_stat;

	dir_file = get_file_dir(file);
	if (dir_file && access(dir_file, F_OK) == -1)
		ft_perror_row(file, "no such file or directory\n", vars);
	else if (dir_file && access(dir_file, W_OK) == -1)
		ft_perror_row(file, "permision denied\n", vars);
	else if (stat(file, &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
		ft_perror_row(file, "is a directory\n", vars);
	else
	{
		fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
		if (access(file, W_OK) == -1)
			ft_perror_row(file, "permision denied\n", vars);
		else if (fd == -1)
			ft_perror_row(NULL, "error while creating the file\n", vars);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	free(dir_file);
}

static void	append_redir_t(char *file, t_vars *vars)
{
	int			fd;
	char		*dir_file;
	struct stat	file_stat;

	dir_file = get_file_dir(file);
	if (dir_file && access(dir_file, F_OK) == -1)
		ft_perror_row(file, "no such file or directory\n", vars);
	else if (dir_file && access(dir_file, W_OK) == -1)
		ft_perror_row(file, "permision denied\n", vars);
	else if (stat(file, &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
		ft_perror_row(file, "is a directory\n", vars);
	else
	{
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
		if (access(file, W_OK) == -1)
			ft_perror_row(file, "permision denied\n", vars);
		if (fd == -1)
			ft_perror_row(NULL, "error while creating the file\n", vars);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	free(dir_file);
}

void	handle_redir(t_redirection_a *redir, t_vars *vars)
{
	t_redirection_a	*voyager_one;

	voyager_one = redir;
	while (voyager_one)
	{
		if (ft_strncmp_a(voyager_one->type, "<") == 0)
			input_redir_t(voyager_one->file, vars);
		else if (ft_strncmp_a(voyager_one->type, ">") == 0)
			output_redir_t(voyager_one->file, vars);
		else if (ft_strncmp_a(voyager_one->type, ">>") == 0)
			append_redir_t(voyager_one->file, vars);
		voyager_one = voyager_one->next;
	}
}

void	handle_cmd(t_pipe_a pipe_a, int input_fd, int output_fd, t_vars *vars)
{
	if (pipe_a.prev && input_fd != 0)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (pipe_a.next && output_fd != 1)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
	handle_redir(pipe_a.cmd->redir, vars);
	if (is_built_ins(pipe_a.cmd))
		exec_built_ins_w(pipe_a.cmd, vars);
	else
		ft_execve_path(pipe_a.cmd->cmd, pipe_a.cmd->args, vars);
}
