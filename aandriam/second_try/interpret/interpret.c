/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:56:13 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/02 14:20:41 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_protocol(t_vars *vars, char **input)
{
	free(vars->history_dir);
	free(vars->log_dir);
	free(vars->heredoc_dir);
	free(vars->err);
	free(*input);
	exit(0);
}

char	*nice_prompt(void)
{
	char	*res;
	char	*tmp;
	char	buffer[1024];

	getcwd(buffer, 1024);
	tmp = ft_strjoin("\033[38;2;166;227;161m╭\033[38;2;148;226;213m ", buffer);
	res = ft_strjoin(tmp, "\033[38;2;137;180;250m \n╰ \033[0m");
	free(tmp);
	return (res);
}

void	ft_add_history(char *input, t_vars *vars)
{
	int	fd;

	if (input[0] != '\n')
	{
		fd = open(vars->history_dir, O_RDWR | O_APPEND);
		if (fd == -1)
			exit(1);
		ft_putstr_fd(input, fd);
		ft_putstr_fd("\n", fd);
		add_history(input);
		close(fd);
	}
}
