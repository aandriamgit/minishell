/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redir_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:14:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/12 17:10:59 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../simple_execution.h"

int	file_exist(char *dir)
{
	if (access(dir, F_OK) == 0)
		return (1);
	free(dir);
	return (0);
}

char	*take_input(char *dir)
{
	char	*input;
	char	*lol;
	char	*tmp;
	int		fd;

	lol = get_next_line(fd);
	while (tmp)
	{
		tmp = get_next_line(fd);
		input = ft_strjoin(lol, tmp);
	}
	return (input);
}
