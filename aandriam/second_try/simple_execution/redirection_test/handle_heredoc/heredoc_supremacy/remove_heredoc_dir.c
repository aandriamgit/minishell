/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_heredoc_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:56:27 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/04 13:09:51 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../simple_execution.h"

void	remove_heredoc_dir(t_vars *vars)
{
	char	*cmd;
	char	**args;

	cmd = ft_strdup("/bin/rm");
	args = malloc(sizeof(char *) * 4);
	args[0] = ft_strdup("rm");
	args[1] = ft_strdup("-rf");
	args[2] = ft_strdup(vars->heredoc_dir);
	args[3] = NULL;
	ft_execve(cmd, args);
	free(cmd);
	ft_free_all(&args);
}
