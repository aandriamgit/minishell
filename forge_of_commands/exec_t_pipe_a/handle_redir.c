/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:34:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/15 22:32:34 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_t_pipe_a.h"

static void	input_redir_n(char *file, t_vars *vars, int *flag)
{
	int			fd;
	struct stat	file_stat;

	*flag = 0;
	if (stat(file, &file_stat) == -1)
		ft_perror_redir(file, vars, ENOENT, 1);
	else if (access(file, R_OK) == -1)
		ft_perror_redir(file, vars, EACCES, 1);
	else if (S_ISDIR(file_stat.st_mode))
		ft_perror_redir(file, vars, EISDIR, 1);
	else
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_perror_redir(file, vars, errno, 1);
		else
		{
			dup2(fd, STDIN_FILENO);
			*flag = 1;
		}
		close(fd);
	}
}

static void	output_redir_n(char *file, t_vars *vars, int *flag)
{
	int			fd;
	struct stat	file_stat;

	*flag = 0;
	if (stat(file, &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
	{
		if (access(file, W_OK) == -1)
			ft_perror_redir(file, vars, EACCES, 1);
		else
			ft_perror_redir(file, vars, EISDIR, 1);
	}
	else
	{
		fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
		if (fd == -1)
			ft_perror_redir(file, vars, errno, 1);
		else
		{
			dup2(fd, STDOUT_FILENO);
			close(fd);
			*flag = 1;
		}
	}
}

static void	append_redir_n(char *file, t_vars *vars, int *flag)
{
	int			fd;
	struct stat	file_stat;

	*flag = 0;
	if (stat(file, &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
	{
		if (access(file, W_OK) == -1)
			ft_perror_redir(file, vars, EACCES, 1);
		else
			ft_perror_redir(file, vars, EISDIR, 1);
	}
	else
	{
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
		if (fd == -1)
			ft_perror_redir(file, vars, errno, 1);
		else
		{
			dup2(fd, STDOUT_FILENO);
			*flag = 1;
		}
		close(fd);
	}
}

void	handle_redir(t_redirection_a *redir, t_vars *vars, int *flag)
{
	t_redirection_a	*voyager_one;

	voyager_one = redir;
	*flag = 1;
	while (voyager_one && *flag)
	{
		if (ft_strncmp_a(voyager_one->type, "<") == 0)
			input_redir_n(voyager_one->file, vars, flag);
		else if (ft_strncmp_a(voyager_one->type, ">") == 0)
			output_redir_n(voyager_one->file, vars, flag);
		else if (ft_strncmp_a(voyager_one->type, ">>") == 0)
			append_redir_n(voyager_one->file, vars, flag);
		voyager_one = voyager_one->next;
	}
}
