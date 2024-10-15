/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:31:33 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/11 11:11:50 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	p_test(t_vars *vars)
{
	t_pipe	*v_one;
	char	*buff;

	vars->pipe = parsing_test();
	v_one = vars->pipe;
	while (v_one->next)
	{
		buff = get_output(v_one, vars);
		v_one = v_one->next;
		exit(0);
		use_as_input(&buff, v_one);
	}
}

void	redir_test(t_vars *vars)
{
	ft_putstr_fd("\n[x] standard output test\n", 1);
	s_o_test(vars);
	ft_putstr_fd("\n[x] append test\n", 1);
	append_test(vars);
	ft_putstr_fd("\n[x] standard output and errors test\n", 1);
	s_o_errors_test(vars);
}
