/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 09:21:29 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/21 16:19:07 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../first_test.h"

void	ft_perror(char *file, char *str)
{
	int		fd;
	char	**args;

	args = malloc(sizeof(char **));
	args[0] = NULL;
	fd = open("/dev/null", O_WRONLY);
	ft_putstr_fd("minishell: ", 1);
	if (file)
	{
		ft_putstr_fd(file, 1);
		ft_putstr_fd(": ", 1);
	}
	ft_putstr_fd(str, 1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve_lol("ls", args);
}

void	input_redir(char *file)
{
	int	fd;

	if (access(file, F_OK) == -1)
		ft_perror(file, "no such file or directory\n");
	else if (access(file, R_OK) == -1)
		ft_perror(file, "permision denied\n");
	else
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_perror(NULL, "error while creating the file\n");
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	output_redir(char *file)
{
	int		fd;
	char	*dir_file;

	dir_file = get_file_dir(file);
	if (dir_file && access(dir_file, F_OK) == -1)
		ft_perror(file, "no such file or directory\n");
	else if (dir_file && access(dir_file, W_OK) == -1)
		ft_perror(file, "permision denied\n");
	else
	{
		fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
		if (access(file, W_OK) == -1)
			ft_perror(file, "permision denied\n");
		else if (fd == -1)
			ft_perror(NULL, "error while creating the file\n");
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	free(dir_file);
}

void	append_redir(char *file)
{
	int		fd;
	char	*dir_file;

	dir_file = get_file_dir(file);
	if (dir_file && access(dir_file, F_OK) == -1)
		ft_perror(file, "no such file or directory\n");
	else if (dir_file && access(dir_file, W_OK) == -1)
		ft_perror(file, "permision denied\n");
	else
	{
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
		if (access(file, W_OK) == -1)
			ft_perror(file, "permision denied\n");
		if (fd == -1)
			ft_perror(NULL, "error while creating the file\n");
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	free(dir_file);
}

void	heredoc_redir(char *file)
{
	(void)file;
	ft_putstr_fd("dude, what the hell is even that\n", 1);
}
