/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:05 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/22 12:59:02 by aandriam         ###   ########.fr       */
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
	fd = open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
	terminate_shell_init(big_param);
	close(fd);
}

void	interpret(char **input, t_vars *vars)
{
	*input = ft_readline("minishell > ");
	ft_add_history(*input, *vars);
	if (ft_strncmp(*input, "exit\n") == 0)
	{
		free(vars->history_dir);
		free(vars->log_dir);
		free(*input);
		exit(1);
	}
}

void	path_execution(char *input)
{
	(void)input;
	ft_putstr_fd("path_execution\n", 1);
}

void	simple_execution(char *input)
{
	(void)input;
	ft_putstr_fd("simple_execution\n", 1);
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
			if (input[0] == '.' || input[0] == '/')
				path_execution(input);
			else
				simple_execution(input);
			free(input);
		}
	}
	else
		printf("[Error] minishell doesn't need arguments\n");
	return (0);
}
