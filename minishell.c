/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:05 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/22 17:05:21 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(t_vars *vars)
{
	char	**big_param;
	int		fd;

	vars_init(vars);
	big_param_init(&big_param, *vars);
	if (access(vars->history_dir, F_OK) == 0)
	{
		terminate_shell_init(big_param);
		return ;
	}
	else
		fork_mkdir(big_param);
	terminate_shell_init(big_param);
	fd = open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
	close(fd);
}

void	interpret(char **input, t_vars *vars)
{
	*input = ft_readline("minishell > ");
	ft_add_history(*input, vars);
	if (ft_strncmp(*input, "exit\n") == 0)
		exit_protocol(vars, input);
	purification(input);
	vars->input = *input;
}

void	path_execution(char *input)
{
	(void)input;
	ft_putstr_fd("path_execution\n", 1);
}

void	simple_execution(t_vars *vars)
{
	if (have_pipe(vars))
		pipe_exec(vars);
	else
		no_pipe_exec(vars);
}

int	main(int argc, char **argv)
{
	char	*input;
	t_vars	vars;

	(void)argv;
	if (argc == 1)
	{
		shell_init(&vars);
		while (1)
		{
			interpret(&input, &vars);
			// if (input[0] == '.' || input[0] == '/')
			// 	path_execution(&vars);
			// else
			simple_execution(&vars);
			free(input);
		}
	}
	else
		printf("[Error] minishell doesn't need argument(s)\n");
	return (0);
}
