/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:56:13 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/17 15:54:24 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_protocol(t_vars *vars, char **input)
{
	free(vars->history_dir);
	free(vars->log_dir);
	free(vars->heredoc_dir);
	free(vars->stderr_a->dir);
	free(vars->stderr_a);
	free(vars->quote_dir);
	free(*input);
	ft_free_t_list(&vars->env);
	exit(0);
}

char	*nice_prompt(void)
{
	char	*tmp;
	char	*lol;
	char	buffer[1024];

	getcwd(buffer, 1024);
	lol = ft_strdup("\001\033[38;2;166;227;161m\022");
	tmp = ft_strjoin_free_a(lol, "\001╭\002\001\033[38;2;148;226;213m\002 ");
	tmp = ft_strjoin_free_a(tmp, buffer);
	tmp = ft_strjoin_free_a(tmp, "\001\033[38;2;137;180;250m\002  \n");
	tmp = ft_strjoin_free_a(tmp, "\001\033[38;2;137;180;250m\002");
	tmp = ft_strjoin_free_a(tmp, "\001╰\002\001\002\001\002\001\002");
	tmp = ft_strjoin_free_a(tmp, "\001\002\001\033[0m\002 ");
	return (tmp);
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
	}
}
