/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:38:40 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/03 14:08:03 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	upload_exit_code(int nbr)
{
	char	*home_dir;
	char	*dir;
	int		fd;

	home_dir = ft_strjoin_a(getenv("HOME"), "/.minishell_log");
	if (access(home_dir, F_OK) != -1)
	{
		dir = ft_strjoin_free_a(home_dir, "/.exit_code_dir");
		fd = open(dir, O_TRUNC | O_WRONLY | O_CREAT, 0755);
		ft_putnbr_fd_a(nbr, fd);
		close(fd);
		free(dir);
	}
}

int	download_exit_code(t_vars *vars)
{
	int		nbr;
	int		fd;
	char	*lol;

	nbr = 0;
	fd = open(vars->exit_code_dir, O_RDONLY);
	if (fd)
	{
		lol = get_next_line(fd);
		if (lol)
		{
			nbr = ft_atoi_a(lol);
			free(lol);
			close(fd);
			fd = open(vars->exit_code_dir, O_TRUNC | O_WRONLY | O_CREAT, 0755);
			ft_putnbr_fd_a(0, fd);
			close(fd);
		}
	}
	return (nbr);
}
