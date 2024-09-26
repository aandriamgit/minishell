/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_special_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:25:50 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/25 17:42:36 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_cd(t_vars *vars)
{
	(void)vars;
}

void	exec_export(t_vars *vars)
{
	(void)vars;
}

void	exec_unset(t_vars *vars)
{
	(void)vars;
}

void	exec_env(t_vars *vars)
{
	ft_putstr_fd("voici env mais pas encore fini\n", 1);
	(void)vars;
}

void	exec_echo(t_vars *vars)
{
	(void)vars;
}
