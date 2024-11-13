/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:25:37 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 07:54:51 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void	extras(char *file, char *str, t_vars *vars)
{
	int		fd;
	int		err;
	char	*err_dir;
	char	**args;

	err_dir = vars->stderr_a->dir;
	err = open(err_dir, O_WRONLY | O_APPEND);
	free(err_dir);
	args = malloc(sizeof(char **));
	args[0] = NULL;
	fd = open("/dev/null", O_WRONLY);
	if (file || str)
		ft_putstr_fd_a("[minishell] ", err);
	if (file)
	{
		ft_putstr_fd_a(file, err);
		ft_putstr_fd_a(": ", err);
	}
	if (str)
		ft_putstr_fd_a(str, err);
	close(err);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve_row("ls", args);
	ft_putstr_fd_a("smt went wrong", err);
}

void	ft_perror_fork(char *file, char *str, t_vars *vars)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		extras(file, str, vars);
	else if (pid < 0)
		ft_perror_row("fork error\n", NULL, vars);
	else
		wait(NULL);
}

void	ft_perror_row(char *file, char *str, t_vars *vars)
{
	int		fd;
	int		err;
	char	*err_dir;
	char	**args;

	err_dir = vars->stderr_a->dir;
	err = open(err_dir, O_WRONLY | O_APPEND);
	args = malloc(sizeof(char **));
	args[0] = NULL;
	fd = open("/dev/null", O_WRONLY);
	if (file || str)
		ft_putstr_fd_a("[minishell] ", err);
	if (file)
	{
		ft_putstr_fd_a(file, err);
		ft_putstr_fd_a(": ", err);
	}
	if (str)
		ft_putstr_fd_a(str, err);
	close(err);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve_row("ls", args);
	ft_putstr_fd_a("smt went wrong in ft_execve_row\n", err);
}
