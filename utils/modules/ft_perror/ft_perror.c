/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:25:37 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/16 17:20:24 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../interpret/interpret.h"
#include "../../../minishell.h"
#include "../../utils.h"
#include <errno.h>

static void	extras(char *file)
{
	char	*joined;

	if (file)
	{
		joined = ft_strjoin_a("[minishell] ", file);
		perror(joined);
		free(joined);
	}
}

void	ft_perror_redir(char *file, t_vars *vars, int err, int nbr)
{
	char	*lol;

	if (err == EACCES)
	{
		errno = err;
		ft_perror_soft(file, "permision denied\n", vars, nbr);
	}
	else if (err == ENOENT)
	{
		errno = err;
		ft_perror_soft(file, "no such file or directory\n", vars, nbr);
	}
	else if (err == EISDIR)
	{
		errno = err;
		ft_perror_soft(file, "is a directory\n", vars, nbr);
	}
	else if (errno != 0)
	{
		lol = ft_strjoin_a("[minishell] ", file);
		perror(lol);
		free(lol);
		vars->exit_code_int = nbr;
	}
}

void	ft_perror_soft(char *file, char *str, t_vars *vars, int nbr)
{
	if (custom_error(file, str, vars))
		extras(file);
	vars->exit_code_int = nbr;
}

void	ft_perror_exit(char *file, char *str, t_vars *vars, int nbr)
{
	if (file && str)
	{
		if (custom_error(file, str, vars))
			extras(file);
	}
	ft_free_t_pipe_a(vars->t_pipe_a);
	ft_free_t_pipe_again(&vars->t_pipe_a);
	free_vars(vars);
	exit(nbr);
}