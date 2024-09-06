/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:38:04 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/06 14:47:30 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_readline(void)
{
	char	*buffer;

	buffer = malloc(1025);
	buffer[1024] = '\0';
	read(0, buffer, 1024);
	if (ft_strncmp(buffer, "exit\n") == 0)
	{
		free(buffer);
		exit(0);
	}
	ft_readline_history(buffer);
	free(buffer);
}
