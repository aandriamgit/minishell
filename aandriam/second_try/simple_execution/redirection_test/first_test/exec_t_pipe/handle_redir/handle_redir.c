/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 09:21:29 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/20 09:54:04 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../first_test.h"

void	input_redir(char *file)
{
	int	fd;

	if (access(file, F_OK) != -1)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			perror("error opening the file\n");
			return ;
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
	{
		ft_putstr_fd("minishell: ", 1);
		ft_putstr_fd(file, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		exit(1);
	}
}

void	output_redir(char *file)
{
	(void)file;
	ft_putstr_fd("here is the output_redir function\n", 1);
	exit(1);
}

void	append_redir(char *file)
{
	(void)file;
	ft_putstr_fd("work still on progress fsfa\n", 1);
}

void	heredoc_redir(char *file)
{
	(void)file;
	ft_putstr_fd("dude, what the hell is even that\n", 1);
}