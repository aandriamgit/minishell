/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:29:30 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/07 18:05:08 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../first_test.h"

void	error_check(char **args)
{
	struct stat	path_stat;

	if (stat(args[1], &path_stat) == -1)
		ft_perror(args[1], "cd: No such file or directory\n");
	if (!S_ISDIR(path_stat.st_mode))
		ft_perror(args[1], "cd: Not a directory\n");
	if (access(args[1], X_OK) == -1)
		ft_perror(args[1], "cd: Permission denied\n");
}

void	update_pwd_env(char *dir)
{
	(void)dir;
}

void	update_oldpwd_env(char *dir)
{
	(void)dir;
}

void	ft_cd(t_command *cmd)
{
	int		i;
	char	**tab;

	tab = cmd->args;
	i = 0;
	while (tab[i])
		i++;
	if (i > 2)
		ft_perror("cd", "too many arguments\n");
	error_check(tab);
	if (chdir(tab[1]) == -1)
		ft_perror(tab[1], "cd: Failed to change directory\n");
	update_pwd_env(tab[1]);
	update_oldpwd_env(tab[1]);
	ft_perror(NULL, NULL);
}
