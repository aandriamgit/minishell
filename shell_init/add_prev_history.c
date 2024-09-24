/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prev_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:13:13 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/24 15:02:49 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lol(char **lol)
{
	int	i;

	i = ft_strlen(*lol);
	(*lol)[i - 1] = '\0';
}

void	add_prev_history(t_vars *vars)
{
	char	*prev;
	int		fd;

	fd = open(vars->history_dir, O_RDONLY);
	prev = get_next_line(fd);
	if (!prev)
		return ;
	lol(&prev);
	add_history(prev);
	while (prev)
	{
		free(prev);
		prev = get_next_line(fd);
		if (!prev)
			return ;
		lol(&prev);
		add_history(prev);
	}
	close(fd);
}
