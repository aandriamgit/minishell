/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uptade_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:25:39 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/17 13:07:12 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpret.h"

static void	special_strjoin(char **to_add, char *tmp)
{
	char	*john;

	if (*to_add)
	{
		john = ft_strjoin_a(*to_add, tmp);
		free(*to_add);
	}
	else
		john = ft_strdup_a(tmp);
	*to_add = john;
}

void	uptade_input(char **input, t_vars *vars)
{
	int		fd;
	char	*to_add;
	char	*tmp;
	char	*lol;

	to_add = ft_strdup_a("\n");
	fd = open(vars->quote_dir, O_RDONLY);
	tmp = get_next_line(fd);
	special_strjoin(&to_add, tmp);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp)
			special_strjoin(&to_add, tmp);
	}
	lol = ft_strjoin_a(*input, to_add);
	free(to_add);
	free(*input);
	*input = lol;
	close(fd);
}
