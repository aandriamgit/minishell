/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:32:43 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/21 16:42:51 by aandriam         ###   ########.fr       */
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
	input_redir_test("\n []-------------------[]\ninit tests for redirection '<'\n []-------------------[]\n\n");
	output_redir_test("\n []-------------------[]\ninit tests for redirection '>'\n []-------------------[]\n");
	append_redir_test("\n []-------------------[]\ninit tests for redirection '>>'\n []-------------------[]\n\n");
	multi_redir_test("\n []-------------------[]\ninit tests for combined redirections\n []-------------------[]\n\n");
}
