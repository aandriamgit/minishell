/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_supremacy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:15:38 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/05 20:13:10 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_supremacy.h"

static void	remove_heredoc_dir(t_vars *vars)
{
	char	*cmd;
	char	**args;

	cmd = ft_strdup_a("/bin/rm");
	args = malloc(sizeof(char *) * 4);
	args[0] = ft_strdup_a("rm");
	args[1] = ft_strdup_a("-rf");
	args[2] = ft_strdup_a(vars->heredoc_dir);
	args[3] = NULL;
	ft_execve_fork(cmd, args);
	free(cmd);
	ft_free_tab(&args);
}

static void	gen_heredoc_dir(t_vars *vars)
{
	char	**args;
	char	*cmd;
	char	*log_dir;
	int		fd_log;

	cmd = ft_strdup_a("/bin/mkdir");
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup_a("mkdir");
	args[1] = ft_strdup_a(vars->heredoc_dir);
	args[2] = NULL;
	ft_execve_fork(cmd, args);
	ft_free_tab(&args);
	log_dir = ft_strjoin_a(vars->heredoc_dir, "/.log");
	fd_log = open(log_dir, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	ft_putstr_fd_a("1\n", fd_log);
	close(fd_log);
	free(log_dir);
	free(cmd);
}

static void	extra(t_pipe_a **pipe_a, t_vars *vars)
{
	t_pipe	*cmd;
	char	*tmp;

	tmp = ft_strdup_a(vars->save_heredoc);
	ft_free_t_pipe_a(*pipe_a);
	ft_free_t_pipe_again(pipe_a);
	*pipe_a = NULL;
	check_input(&tmp);
	formating(&tmp, vars->env, vars);
	cmd = gen_pipe(&tmp);
	*pipe_a = convert_t_pipe_a(cmd);
	free_pipe(&vars->cmd);
	vars->cmd = cmd;
	vars->exit_code_int = 0;
}

void	heredoc_supremacy(t_pipe_a **pipe_a, t_vars *vars, int *flag)
{
	char	*eof;
	int		nb;

	nb = 1;
	remove_heredoc_dir(vars);
	while (have_heredoc(*pipe_a))
	{
		if (access(vars->heredoc_dir, F_OK) != 0)
			gen_heredoc_dir(vars);
		eof = get_eof(*pipe_a);
		init_heredoc(vars, eof, nb);
		purify_from_heredoc(pipe_a, vars->heredoc_dir, nb);
		nb++;
		if (vars->exit_code_int == 130)
		{
			extra(pipe_a, vars);
			return ;
		}
	}
	*flag = 0;
}
