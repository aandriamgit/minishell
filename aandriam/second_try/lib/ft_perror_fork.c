/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:50:36 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/08 10:58:00 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_err_dir(void)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(getenv("HOME"), "/.minishell_log");
	res = ft_strjoin(tmp, "/.err_log");
	free(tmp);
	return (res);
}

static void	extras(char *file, char *str)
{
	int		fd;
	int		err;
	char	*err_dir;
	char	**args;

	err_dir = get_err_dir();
	err = open(err_dir, O_WRONLY | O_APPEND);
	free(err_dir);
	args = malloc(sizeof(char **));
	args[0] = NULL;
	fd = open("/dev/null", O_WRONLY);
	if (file || str)
		ft_putstr_fd("[minishell] ", err);
	if (file)
	{
		ft_putstr_fd(file, err);
		ft_putstr_fd(": ", err);
	}
	if (str)
		ft_putstr_fd(str, err);
	close(err);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve_lol("ls", args);
	ft_putstr_fd("smt went wrong", err);
}

void	ft_perror_fork(char *file, char *str)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		extras(file, str);
	else if (pid < 0)
		ft_perror("fork error\n", NULL);
	else
		wait(NULL);
}
