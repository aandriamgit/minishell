/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:24:19 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/03 09:13:17 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "shell_init.h"
#include <bits/types/siginfo_t.h>

void	vars_init(t_vars *vars, t_list **env_cpy)
{
	vars->log_dir = ft_strjoin_a(getenv("HOME"), "/.minishell_log");
	vars->history_dir = ft_strjoin_a(vars->log_dir, "/.minishell_history");
	vars->env = *env_cpy;
	vars->stderr_a = ft_strjoin_a(vars->log_dir, "/.stderr_a_dir");
	vars->stderr_log = ft_strjoin_a(vars->stderr_a, "/stderr_log");
	vars->heredoc_dir = ft_strjoin_a(vars->log_dir, "/.heredoc_dir");
	vars->exit_code_dir = ft_strjoin_a(vars->log_dir, "/.exit_code_dir");
	vars->quote_dir = ft_strjoin_a(vars->log_dir, "/.quote_dir");
	vars->custom_prompt = 0;
	vars->custom_flag = 0;
	vars->exit_code_int = 0;
	vars->err_nbr = 0;
	vars->input = NULL;
	vars->cmd = NULL;
	vars->cmd = NULL;
	vars->save_heredoc = NULL;
	vars->exit_code_int = 0;
}

void	big_param_init(char ***big_param, t_vars vars)
{
	*big_param = malloc(sizeof(char *) * 3);
	if (*big_param == NULL)
		exit(0);
	(*big_param)[0] = ft_strdup_a("mkdir");
	(*big_param)[1] = ft_strdup_a(vars.log_dir);
	(*big_param)[2] = NULL;
}

void	add_prev_history(t_vars *vars)
{
	char	*prev;
	int		fd;

	fd = open(vars->history_dir, O_RDONLY);
	prev = get_next_line(fd);
	if (!prev)
		return ;
	prev[ft_strlen_a(prev) - 1] = '\0';
	add_history(prev);
	while (prev)
	{
		free(prev);
		prev = get_next_line(fd);
		if (!prev)
		{
			close(fd);
			return ;
		}
		prev[ft_strlen_a(prev) - 1] = '\0';
		add_history(prev);
	}
	close(fd);
}

void	creat_files(t_vars *vars)
{
	int	fd;

	if (access(vars->history_dir, F_OK) == 0)
		add_prev_history(vars);
	else
	{
		fd = open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
		close(fd);
	}
	fd = open(vars->exit_code_dir, O_TRUNC | O_WRONLY | O_CREAT, 0755);
	ft_putnbr_fd_a(0, fd);
	close(fd);
}

void	handler(int signum, siginfo_t *s_siginfo, void *context)
{
	char	*lol;

	(void)context;
	if (signum == SIGINT)
	{
		upload_exit_code(130);
		printf("\n");
		rl_replace_line("", 1);
		if (s_siginfo->si_pid > 0)
		{
			lol = get_magic_prompt();
			printf("%s", lol);
			free(lol);
		}
	}
}
