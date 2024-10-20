/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:32:43 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/20 16:50:52 by aandriam         ###   ########.fr       */
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
	first_test(ft_strdup("cat"), ft_strdup("<"), ft_strdup("input.txt"));
	ft_putstr_fd("\nredirection test with 'ls < not_existing_file.txt'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup("<"),
		ft_strdup("not_existing_file.txt"));
	ft_putstr_fd("\nredirection test with 'cat < no_permission.txt'\n", 1);
	first_test(ft_strdup("cat"), ft_strdup("<"),
		ft_strdup("no_permission.txt"));
	ft_putstr_fd("\nredirection test with 'cat < empty.txt'\n\n", 1);
	first_test(ft_strdup("cat"), ft_strdup("<"), ft_strdup("empty.txt"));
	ft_putstr_fd("\nredirection test with 'ls > output.txt'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup(">"), ft_strdup("output.txt"));
}
