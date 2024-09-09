/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:04:27 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/09 14:05:19 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	number_of_line(int fd)
{
	char	tmp;
	int		n_read;
	int		i;

	n_read = 1;
	i = 1;
	while (n_read)
	{
		n_read = read(fd, &tmp, 1);
		if (n_read == -1)
			return (-1);
		if (n_read == 0)
			return (i);
		if (tmp == '\n')
			i++;
	}
	return (i);
}
