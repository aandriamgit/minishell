/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:23:39 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/06 16:27:48 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	read_size_buffer(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	simple_read_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	number_of_line(int fd)
{
	char	tmp;
	int		n_read;
	int		i;

	n_read = 1;
	i = 1;
	while (n_read)
	{
		n_read = read(fd, &tmp, 1);
		if (n_read == -1)
			return (-1);
		if (n_read == 0)
			return (i);
		if (tmp == '\n')
			i++;
	}
	return (i);
}

void	ft_readline_history(char *buffer)
{
	int			fd;
	static int	nb;

	if (buffer[0] != '\n')
	{
		fd = open("ft_readline/.minishell_history", O_RDWR | O_APPEND);
		if (fd == -1)
			exit(1);
		nb = number_of_line(fd);
		ft_putnbr_fd(nb, fd);
		write(fd, ". ", 2);
		write(fd, buffer, ft_strlen(buffer));
	}
}
