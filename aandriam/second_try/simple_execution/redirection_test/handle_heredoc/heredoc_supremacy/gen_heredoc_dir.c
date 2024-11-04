/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_heredoc_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:59:35 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/04 13:13:21 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../simple_execution.h"

void	gen_heredoc_dir(t_vars *vars)
{
	char	**args;
	char	*cmd;
	char	*log_dir;
	int		fd_log;

	cmd = ft_strdup("/bin/mkdir");
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("mkdir");
	args[1] = ft_strdup(vars->heredoc_dir);
	args[2] = NULL;
	ft_execve(cmd, args);
	ft_free_all(&args);
	log_dir = ft_strjoin(vars->heredoc_dir, "/.log");
	fd_log = open(log_dir, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	ft_putstr_fd("1\n", fd_log);
	close(fd_log);
	free(log_dir);
	free(cmd);
}
