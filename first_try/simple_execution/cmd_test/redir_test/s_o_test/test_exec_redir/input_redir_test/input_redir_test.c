/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redir_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:14:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/14 15:29:22 by aandriam         ###   ########.fr       */
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

	fd = open(dir, O_RDONLY);
	lol = get_next_line(fd);
	if (lol)
		input = ft_strdup(lol);
	while (lol)
	{
		free(lol);
		lol = get_next_line(fd);
		if (!lol)
		{
			free(dir);
			return (input);
		}
		tmp = ft_strdup(input);
		free(input);
		input = ft_strjoin(lol, tmp);
		free(tmp);
	}
	close(fd);
	free(dir);
	return (input);
}
