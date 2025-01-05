/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_w.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:58:59 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/05 20:35:55 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

static int	error_check(char *args, t_vars *vars)
{
	struct stat	path_stat;

	if (args == NULL)
		ft_perror_exit("cd", "HOME not set\n", vars, 1);
	if (stat(args, &path_stat) == -1)
	{
		ft_perror_exit(args, "cd: No such file or directory\n", vars, 1);
		return (0);
	}
	if (!S_ISDIR(path_stat.st_mode))
	{
		ft_perror_exit(args, "cd: Not a directory\n", vars, 1);
		return (0);
	}
	if (access(args, X_OK) == -1)
	{
		ft_perror_exit(args, "cd: Permission denied\n", vars, 1);
		return (0);
	}
	return (1);
}

static void	go_home(t_vars *vars)
{
	char	*home_dir;

	home_dir = ft_getenv("HOME", vars->env);
	if (!error_check(home_dir, vars))
	{
		if (home_dir)
			free(home_dir);
		ft_perror_exit(home_dir, "HOME not set\n", vars, 1);
		return ;
	}
	if (chdir(home_dir) == -1)
		ft_perror_exit(home_dir, "cd: Failed to change directory\n", vars, 1);
	if (home_dir)
		free(home_dir);
	home_dir = NULL;
}

static void	extras(t_command_a *cmd, t_vars *vars)
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
		ft_perror_exit("cd", "too many arguments\n", vars, 1);
		return ;
	}
	if (tab[1] && !error_check(tab[1], vars))
		return ;
	if (tab[1] && chdir(tab[1]) == -1)
	{
		ft_perror_exit(tab[1], "cd: Failed to change directory\n", vars, 1);
		return ;
	}
}

void	ft_cd_w(t_command_a *cmd, t_vars *vars)
{
	char	**tab;

	tab = cmd->args;
	if (tab[1] && !error_check(tab[1], vars))
		extras(cmd, vars);
	extras(cmd, vars);
	ft_perror_exit(NULL, NULL, vars, 0);
}
