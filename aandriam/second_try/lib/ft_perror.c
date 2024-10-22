/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:22:48 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/22 17:23:09 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
