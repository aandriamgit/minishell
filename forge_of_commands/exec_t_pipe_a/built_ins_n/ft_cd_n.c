/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:21 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:32:17 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_n.h"

static int	error_check(char *args, t_vars *vars)
{
	struct stat	path_stat;

	if (stat(args, &path_stat) == -1)
	{
		ft_perror_soft(args, "cd: No such file or directory\n", vars, 1);
		return (0);
	}
	if (!S_ISDIR(path_stat.st_mode))
	{
		ft_perror_soft(args, "cd: Not a directory\n", vars, 1);
		return (0);
	}
	if (access(args, X_OK) == -1)
	{
		ft_perror_soft(args, "cd: Permission denied\n", vars, 1);
		return (0);
	}
	return (1);
}

static void	update_pwd_oldpwd_env(char *dir)
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
		ft_perror_soft(home_dir, "cd: Failed to change directory\n", vars, 1);
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
		ft_perror_soft("cd", "too many arguments\n", vars, 1);
		return ;
	}
	if (tab[1] && !error_check(tab[1], vars))
		return ;
	if (tab[1] && chdir(tab[1]) == -1)
	{
		ft_perror_soft(tab[1], "cd: Failed to change directory\n", vars, 1);
		return ;
	}
	update_pwd_oldpwd_env(tab[1]);
	vars->exit_code_int = 0;
}

void	ft_cd_n(t_command_a *cmd, t_vars *vars)
{
	int	flag;
	int	save_stdout;
	int	save_stdin;

	flag = 0;
	save_stdout = dup(STDOUT_FILENO);
	save_stdin = dup(STDIN_FILENO);
	handle_redir(cmd->redir, vars, &flag);
	if (flag)
		extras(cmd, vars);
	dup2(save_stdout, STDOUT_FILENO);
	dup2(save_stdin, STDIN_FILENO);
	close(save_stdout);
	close(save_stdin);
}
