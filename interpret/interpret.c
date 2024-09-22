/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:32:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/22 16:10:05 by aandriam         ###   ########.fr       */
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

void	purification(char **input)
{
	int	i;

	i = 0;
	while ((*input)[i] != '\n')
		i++;
	(*input)[i] = '\0';
}
