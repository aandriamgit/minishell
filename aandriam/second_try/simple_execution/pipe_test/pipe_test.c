/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:32:26 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/05 16:49:07 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_test.h"

void	simple_test(char *first, char *second, t_vars *vars)
{
	t_pipe	*p_test;
	t_pipe	*q_test;
	char	**first_big;
	char	**second_big;

	first_big = ft_split(first, ' ');
	second_big = ft_split(second, ' ');
	q_test = gen_pipe_test(gen_cmd(second_big[0], second_big, NULL, NULL), NULL,
			NULL);
	p_test = gen_pipe_test(gen_cmd(first_big[0], first_big, NULL, NULL), NULL,
			NULL);
	if (p_test && q_test)
	{
		add_pipe_next(&p_test, &q_test);
		ft_print_pipe(p_test);
		just_do_it(p_test, vars);
	}
	else
		return ;
}

void	free_test_no_redir(char *str, t_vars *vars)
{
	char	*input;
	t_pipe	*p_test;

	ft_putstr_fd(str, 1);
	ft_putstr_fd("\nyou can input custom prompt, no redir\n", 1);
	if (init_test(&p_test))
	{
		while (1)
		{
			input = readline("your cmd > ");
			if (!input || ft_strncmp(input, "NULL") == 0)
			{
				if (input)
					free(input);
				ft_print_pipe(p_test);
				just_do_it(p_test, vars);
				return ;
			}
			add_input(&p_test, input);
		}
	}
}

void	free_test_w_redir(char *str, t_vars *vars)
{
	char	*input;
	t_pipe	*p_test;

	ft_putstr_fd(str, 1);
	ft_putstr_fd("\nyou can input custom prompt, with redir\n", 1);
	init_err(vars);
	p_test = NULL;
	while (1)
	{
		input = readline("your cmd > ");
		if (!input || ft_strncmp(input, "NULL") == 0)
		{
			if (input)
				free(input);
			ft_print_pipe(p_test);
			just_do_it(p_test, vars);
			return ;
		}
		add_input_w_redir(input, &p_test);
	}
}

void	one_pipe_test(char *str, t_vars *vars)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("pipe test with 'echo ''hello'' | wc -c'\n", 1);
	simple_test("echo hello", "wc -c", vars);
	ft_putstr_fd("\npipe test with 'echo ''hello'' | non_existent_cmd'\n", 1);
	simple_test("echo hello", "non_existent_cmd", vars);
}
