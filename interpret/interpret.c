/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:32:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/24 16:13:50 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_protocol(t_vars *vars, char **input)
{
	free(vars->history_dir);
	free(vars->log_dir);
	free(*input);
	exit(0);
}

char	*nice_prompt(void)
{
	char	*prompt;
	char	*res;
	char	*tmp;
	char	buffer[1024];
	char	*buff;

	getcwd(buffer, 1024);
	prompt = ft_strrchr(buffer, '/');
	prompt++;
	buff = ft_strdup(prompt);
	tmp = ft_strjoin(" \033[38;2;166;227;161m➜ \033[38;2;148;226;213m", buff);
	res = ft_strjoin(tmp, "\033[0m ");
	free(tmp);
	free(buff);
	return (res);
}
