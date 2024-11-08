/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_chill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:45:56 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/08 14:28:58 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../first_test.h"

static int	error_check(char *args)
{
	struct stat	path_stat;

	if (stat(args, &path_stat) == -1)
	{
		ft_perror_fork(args, "cd: No such file or directory\n");
		return (0);
	}
	if (!S_ISDIR(path_stat.st_mode))
	{
		ft_perror_fork(args, "cd: Not a directory\n");
		return (0);
	}
	if (access(args, X_OK) == -1)
	{
		ft_perror_fork(args, "cd: Permission denied\n");
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

static void	go_home(void)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (!error_check(home_dir))
		return ;
	if (chdir(home_dir) == -1)
		ft_perror_fork(home_dir, "cd: Failed to change directory\n");
}

void	ft_cd_chill(t_command *cmd)
{
	int		i;
	char	**tab;

	tab = cmd->args;
	i = 0;
	while (tab[i])
		i++;
	if (i == 1)
		go_home();
	else if (i > 2)
	{
		ft_perror_fork("cd", "too many arguments\n");
		return ;
	}
	if (!error_check(tab[1]))
		return ;
	if (chdir(tab[1]) == -1)
	{
		ft_perror_fork(tab[1], "cd: Failed to change directory\n");
		return ;
	}
	update_pwd_env(tab[1]);
	update_oldpwd_env(tab[1]);
}
