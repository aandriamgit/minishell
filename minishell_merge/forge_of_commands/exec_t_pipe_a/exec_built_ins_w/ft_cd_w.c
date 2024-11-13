/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_w.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:03:04 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 08:38:44 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_built_ins_w.h"

static void	error_check(char **args, t_vars *vars)
{
	struct stat	path_stat;

	if (stat(args[1], &path_stat) == -1)
		ft_perror_row(args[1], "cd: No such file or directory\n", vars);
	if (!S_ISDIR(path_stat.st_mode))
		ft_perror_row(args[1], "cd: Not a directory\n", vars);
	if (access(args[1], X_OK) == -1)
		ft_perror_row(args[1], "cd: Permission denied\n", vars);
}

static void	update_pwd_env(char *dir)
{
	(void)dir;
}

static void	update_oldpwd_env(char *dir)
{
	(void)dir;
}

void	ft_cd_w(t_command_a *cmd, t_vars *vars)
{
	int		i;
	char	**tab;

	tab = cmd->args;
	i = 0;
	while (tab[i])
		i++;
	if (i > 2)
		ft_perror_row("cd", "too many arguments\n", vars);
	error_check(tab, vars);
	if (chdir(tab[1]) == -1)
		ft_perror_row(tab[1], "cd: Failed to change directory\n", vars);
	update_pwd_env(tab[1]);
	update_oldpwd_env(tab[1]);
	ft_perror_row(NULL, NULL, vars);
}
