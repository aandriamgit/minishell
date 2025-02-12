/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:25:20 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/02 10:45:23 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpret/interpret.h"
#include "../utils/utils.h"
#include "forge_of_commands.h"

static char	*get_dir(int tmp, t_vars *vars)
{
	char	*lol;
	char	*char_tmp;

	char_tmp = ft_itoa_a(tmp);
	lol = ft_strjoin_a(vars->stderr_a, "/");
	lol = ft_strjoin_free_a(lol, char_tmp);
	free(char_tmp);
	return (lol);
}

static void	show_it(char *dir)
{
	int		fd;
	char	*tmp;

	fd = open(dir, O_RDONLY);
	tmp = get_next_line(fd);
	ft_putstr_fd_a(tmp, STDERR_FILENO);
	free(tmp);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
}

void	show_errors(t_vars *vars)
{
	int		tmp;
	int		count;
	char	*dir;

	tmp = 0;
	count = vars->err_nbr;
	while (tmp <= count)
	{
		dir = get_dir(tmp, vars);
		if (!access(dir, F_OK))
			show_it(dir);
		free(dir);
		tmp++;
	}
	vars->err_nbr = 0;
	if (vars->input)
	{
		free(vars->input);
		vars->input = NULL;
	}
}

void	terminus(void **pipe_a, t_vars *vars)
{
	show_errors(vars);
	ft_free_t_pipe_a(*pipe_a);
	ft_free_t_pipe_again((t_pipe_a **)pipe_a);
}
