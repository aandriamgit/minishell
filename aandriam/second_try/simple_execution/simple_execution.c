/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:32:43 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/05 16:47:32 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_execution.h"

int	is_special(t_vars *vars)
{
	if (ft_strncmp(vars->input, "pipe_test") == 0)
		return (1);
	else if (ft_strncmp(vars->input, "redirection_test") == 0)
		return (2);
	else if (ft_strncmp(vars->input, "global_test") == 0)
		return (3);
	return (0);
}

void	pipe_test(t_vars *vars)
{
	one_pipe_test("\n []---[]\none pipe test\n []---[]\n\n", vars);
	free_test_no_redir("\n []---[]\nfree pipe test\n []---[]\n\n", vars);
	free_test_w_redir("\n []---[]\nfree pipe test(2)\n []---[]\n\n", vars);
}

void	global_test(t_vars *vars)
{
	(void)vars;
}

void	redirection_test(t_vars *vars)
{
	input_redir_test("\n []---[]\ninput tests '<'\n []---[]\n\n");
	output_redir_test("\n []---[]\noutput tests '>'\n []---[]\n");
	append_redir_test("\n []---[]\nappend tests '>>'\n []---[]\n\n");
	heredoc_redir_test("\n []---[]\nheredoc tests '<<'\n []---[]\n\n", vars);
	multi_redir_test("\n []---[]\ncombined redir tests\n []---[]\n\n");
}
