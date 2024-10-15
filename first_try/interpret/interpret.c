/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:32:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/26 17:48:04 by aandriam         ###   ########.fr       */
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
	char	*res;
	char	*tmp;
	char	buffer[1024];

	getcwd(buffer, 1024);
	tmp = ft_strjoin("\033[38;2;166;227;161m╭\033[38;2;148;226;213m ", buffer);
	res = ft_strjoin(tmp, "\033[38;2;137;180;250m \n╰ \033[0m");
	free(tmp);
	return (res);
}
