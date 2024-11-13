/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:41:59 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 08:48:17 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_built_ins_n.h"

static int	error_check(char *args, t_vars *vars)
{
	struct stat	path_stat;

	if (stat(args, &path_stat) == -1)
	{
		ft_perror_fork(args, "cd: No such file or directory\n", vars);
		return (0);
	}
	if (!S_ISDIR(path_stat.st_mode))
	{
		ft_perror_fork(args, "cd: Not a directory\n", vars);
		return (0);
	}
	if (access(args, X_OK) == -1)
	{
		ft_perror_fork(args, "cd: Permission denied\n", vars);
		return (0);
	}
	return (1);
}

static void	update_pwd_env(char *dir)
{
	(void)dir;
}

static void	update_oldpwd_env(char *dir)
{
	(void)dir;
}

static void	go_home(t_vars *vars)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (!error_check(home_dir, vars))
		return ;
	if (chdir(home_dir) == -1)
		ft_perror_fork(home_dir, "cd: Failed to change directory\n", vars);
}

void	ft_cd_n(t_command_a *cmd, t_vars *vars)
{
	int		i;
	char	**tab;

	tab = cmd->args;
	i = 0;
	while (tab[i])
		i++;
	if (i == 1)
		go_home(vars);
	else if (i > 2)
	{
		ft_perror_fork("cd", "too many arguments\n", vars);
		return ;
	}
	if (!error_check(tab[1], vars))
		return ;
	if (chdir(tab[1]) == -1)
	{
		ft_perror_fork(tab[1], "cd: Failed to change directory\n", vars);
		return ;
	}
	update_pwd_env(tab[1]);
	update_oldpwd_env(tab[1]);
}
