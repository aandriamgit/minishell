/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_special_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:30:40 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/26 16:30:45 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_special_cmd(t_vars *vars)
{
	if (ft_strncmp(vars->input, "cd") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "export") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "unset") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "env") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "echo") == 0)
		return (1);
	return (0);
}
