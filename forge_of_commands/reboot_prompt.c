/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reboot_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:25:14 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/22 15:59:18 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forge_of_commands.h"

void	reboot_prompt(t_vars *vars, t_pipe_a **pipe_a)
{
	char	*dir;
	char	**args;

	(void)pipe_a;
	dir = vars->log_dir;
	args = malloc(sizeof(char *) * 4);
	args[0] = ft_strdup_a("rm");
	args[1] = ft_strdup_a("-rf");
	args[2] = ft_strdup_a(dir);
	args[3] = NULL;
	ft_execve_row(ft_strdup_a("/bin/rm"), args);
}
