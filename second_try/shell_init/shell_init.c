/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:24:19 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/15 16:30:25 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	vars_init(t_vars *vars, char **env)
{
	vars->log_dir = ft_strjoin(getenv("HOME"), "/.minishell_log");
}
