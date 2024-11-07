/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:22:48 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/07 17:13:47 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_err_dir(void)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(getenv("HOME"), "/.minishell_log");
	res = ft_strjoin(tmp, "/.err_log");
	free(tmp);
	return (res);
}

void	ft_perror(char *file, char *str)
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
		ft_putstr_fd("\033[38;2;243;139;168m[minishell]\033[0m ", err);
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
