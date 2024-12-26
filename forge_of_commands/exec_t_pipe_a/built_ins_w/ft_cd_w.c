/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_w.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:58:59 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:34:46 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

static int	error_check(char *args, t_vars *vars)
{
	struct stat	path_stat;

	if (stat(args, &path_stat) == -1)
		ft_perror_exit(args, "cd: No such file or directory\n", vars, 1);
	if (!S_ISDIR(path_stat.st_mode))
		ft_perror_exit(args, "cd: Not a directory\n", vars, 1);
	if (access(args, X_OK) == -1)
		ft_perror_exit(args, "cd: Permission denied\n", vars, 1);
	return (1);
}

void	ft_cd_w(t_command_a *cmd, t_vars *vars)
{
	char	**tab;

	tab = cmd->args;
	if (tab[1] && !error_check(tab[1], vars))
		ft_perror_exit(NULL, NULL, vars, 0);
}
