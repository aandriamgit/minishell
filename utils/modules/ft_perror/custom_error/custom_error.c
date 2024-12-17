/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:35:40 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/16 17:21:49 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../utils.h"
#include <errno.h>

static void	ultimate_perror(char *file, char *str, t_vars *vars, int err)
{
	if (ft_strncmp_a(str, "command not found\n") == 0)
		custom_cmd_not_found(file, str, vars, err);
	else if (errno == EACCES)
		custom_permission_denied(file, str, vars, err);
	else if (errno == ENOENT)
		custom_nosuchfileordir(file, str, vars, err);
	else if (errno == EISDIR)
		custom_is_a_dir(file, str, vars, err);
}

static void	extras(char *file, char *str, t_vars *vars)
{
	int	err;

	err = gen_fd(vars);
	if (file || str)
		ft_putstr_fd_a("[minishell] ", err);
	if (file)
	{
		ft_putstr_fd_a(file, err);
		ft_putstr_fd_a(": ", err);
	}
	if (vars->custom_flag && errno != 0)
		ultimate_perror(file, str, vars, err);
	else
		ft_putstr_fd_a(str, err);
	if (err != 2)
		close(err);
}

int	custom_error(char *file, char *str, t_vars *vars)
{
	if (errno == EACCES || errno == ENOENT || errno == EISDIR || (str
			&& ft_strncmp_a(str, "command not found\n") == 0))
	{
		extras(file, str, vars);
		return (0);
	}
	else if (errno == 0)
	{
		extras(file, str, vars);
		return (0);
	}
	return (1);
}
