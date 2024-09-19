/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:02:09 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/19 15:08:01 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*only_readable(char *buffer)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i++;
	clean = malloc(sizeof(char) * (i + 1));
	if (!clean)
		exit(1);
	clean[i] = '\0';
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		clean[j] = buffer[j];
		j++;
	}
	clean[j] = '\n';
	return (clean);
}
