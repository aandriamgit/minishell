/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:25:20 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/17 16:55:39 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	cat_it(char *dir)
{
	char	**args;
	char	*cmd;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		args = malloc(sizeof(char *) * 3);
		args[0] = ft_strdup_a("cat");
		args[1] = dir;
		args[2] = NULL;
		cmd = ft_strdup_a("/bin/cat");
		execve(cmd, args, NULL);
	}
	else if (pid < 0)
		ft_putstr_fd_a("lol\n", 1);
	else
		wait(NULL);
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
		if (access(dir, F_OK) == 0)
		{
			cat_it(dir);
		}
		free(dir);
		tmp++;
	}
	vars->err_nbr = 0;
}

void	terminus(void **pipe_a, t_vars *vars)
{
	show_errors(vars);
	ft_free_t_pipe_a(*pipe_a);
	ft_free_t_pipe_again((t_pipe_a **)pipe_a);
}
