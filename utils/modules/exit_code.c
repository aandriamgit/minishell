/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:38:40 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/28 08:25:47 by aandriam         ###   ########.fr       */
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

int	can_custom(void)
{
	char	*home_dir;
	char	*dir;
	char	*char_nbr;
	int		fd;
	int		res;

	res = 0;
	home_dir = ft_strjoin_a(getenv("HOME"), "/.minishell_log");
	if (access(home_dir, F_OK) != -1)
	{
		dir = ft_strjoin_free_a(home_dir, "/.can_custom_dir");
		fd = open(dir, O_RDONLY);
		char_nbr = get_next_line(fd);
		res = ft_atoi_a(char_nbr);
		free(char_nbr);
		close(fd);
		free(dir);
	}
	return (res);
}

char	*get_magic_prompt(void)
{
	char	*res;
	char	*tmp;
	char	buffer[1024];
	char	*lol;

	getcwd(buffer, 1024);
	tmp = ft_strjoin_a("\033[38;2;166;227;161m╭\033[38;2;148;226;213m ",
			buffer);
	res = ft_strjoin_free_a(tmp, "\033[38;2;137;180;250m  \033[0m");
	lol = ft_strjoin_free_a(res, "\n\001\033[38;2;243;139;168m\002\001╰\002");
	lol = ft_strjoin_free_a(lol, "\001\002\001\033[0m\002 ");
	return (lol);
}
