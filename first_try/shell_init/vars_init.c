/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:58:37 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/01 12:28:25 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_env_dir_name(t_vars *vars)
{
	char	*dir_name;
	char	*pid;

	/* char	*shlvl; */
	/* char	*tmp; */
	pid = getenv("SYSTEMD_EXEC_PID");
	/* shlvl = getenv("SHLVL"); */
	pid = ft_strrchr(pid, '=');
	/* tmp = ft_strjoin(shlvl, pid); */
	dir_name = ft_strjoin("/env_dir_", pid);
	vars->env_dir_name = ft_strjoin(vars->log_dir, dir_name);
}

void	vars_init(t_vars *vars, char **env)
{
	vars->log_dir = ft_strjoin(getenv("HOME"), "/.minishell_log");
	vars->history_dir = ft_strjoin(vars->log_dir, "/.minishell_history");
	vars->env = env;
	// get_env_dir_name(vars);
	// vars->env_dir = ft_strjoin(vars->log_dir, vars->env_dir_name);
}
