/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec_nopipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:18:15 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/11 10:00:51 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	terminate_nopipe(char *path, char **big_param, t_vars *vars)
{
	free(path);
	free(vars->input);
	free(vars->log_dir);
	free(vars->history_dir);
	free_res(&big_param);
}

void	free_res(char ***res)
{
	int	i;

	i = 0;
	while ((*res)[i])
	{
		free((*res)[i]);
		i++;
	}
	free(*res);
}
