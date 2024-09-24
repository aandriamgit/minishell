/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:04:27 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/24 13:47:36 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

void	ft_add_history(char *input, t_vars *vars)
{
	int	fd;
	int	nb;

	if (input[0] != '\n')
	{
		fd = open(vars->history_dir, O_RDWR | O_APPEND);
		if (fd == -1)
			exit(1);
		nb = number_of_line(fd);
		ft_putstr_fd("==", fd);
		ft_putnbr_fd(nb, fd);
		ft_putstr_fd("== ", fd);
		ft_putstr_fd(input, fd);
		ft_putstr_fd("\n", fd);
		add_history(input);
	}
}
