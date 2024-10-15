/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:57:02 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/12 16:41:37 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../simple_execution.h"

void	s_o_test(t_vars *vars)
{
	ft_putstr_fd("input redirection test with 'cat < input_red.txt'\n", 1);
	vars->pipe = generate_redir("cat", "<", "input_red.txt");
	test_exec_redir(vars->pipe, vars);
	ft_putstr_fd("[ ] work still on progress\n", 1);
}

void	append_test(t_vars *vars)
{
	(void)vars;
	ft_putstr_fd("[ ] work still on progress\n", 1);
}

void	s_o_errors_test(t_vars *vars)
{
	(void)vars;
	ft_putstr_fd("[ ] work still on progress\n\n", 1);
}
