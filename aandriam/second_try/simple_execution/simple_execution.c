/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:32:43 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/17 10:25:32 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_execution.h"

int	is_special(t_vars *vars)
{
	if (ft_strncmp(vars->input, "pipe_test") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "redirection_test") == 0)
		return (2);
	return (0);
}

void	pipe_test(t_vars *vars)
{
	(void)vars;
}

void	redirection_test(t_vars *vars)
{
	(void)vars;
	ft_putstr_fd("redirection test with 'cat < input.txt'\n", 1);
	first_test("cat", "<", "input.txt");
}
