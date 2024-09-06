/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:38:04 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/06 09:33:34 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_readline(void)
{
	static char	buffer[BUFFER_SIZE];
	static char	*tmp;
	int			bytes;

	bytes = read(0, buffer, BUFFER_SIZE);
	if (ft_strncmp(buffer, "exit\n") == 0)
	{
		if (tmp)
			free(tmp);
		exit(0);
	}
	ft_readline_history(buffer, &tmp);
	if (tmp)
		ft_putstr(tmp, 1);
}
