/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:32:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/22 13:35:20 by aandriam         ###   ########.fr       */
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
