/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:12:29 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/02 17:06:16 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(t_vars *vars, char **env)
{
	char	**big_param;

	vars_init(vars, env);
	big_param_init(&big_param, *vars);
	if (access(vars->log_dir, F_OK) == 0)
	{
		ft_free_all(&big_param);
		if (access(vars->history_dir, F_OK) == 0)
			add_prev_history(vars);
		else
			gen_dir(vars);
		return ;
	}
	else
		exec_big_param(big_param);
	gen_dir(vars);
	add_prev_history(vars);
	ft_free_all(&big_param);
}

void	interpret(char **input, t_vars *vars)
{
	char	*prompt;

	prompt = nice_prompt();
	*input = readline(prompt);
	free(prompt);
	if (access(vars->history_dir, F_OK) == 0)
		ft_add_history(*input, vars);
	else if (access(vars->log_dir, F_OK) == -1)
	{
		perror("please dont mess with the minishell_log\n");
		vars = NULL;
		return ;
	}
	else
	{
		perror("please dont mess with the history\n");
		open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
		ft_add_history(*input, vars);
	}
	if (ft_strncmp(*input, "exit") == 0)
		exit_protocol(vars, input);
	vars->input = *input;
}

void	path_execution(t_vars *vars)
{
	(void)vars;
	ft_putstr_fd("path_execution\n", 1);
}

void	simple_execution(t_vars *vars)
{
	int	type;

	type = is_special(vars);
	if (type)
	{
		if (type == 1)
			pipe_test(vars);
		else if (type == 2)
			redirection_test(vars);
		else if (type == 3)
			global_test(vars);
	}
	else
		ft_putstr_fd("not my job\n", 1);
}

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_vars	vars;

	(void)argv;
	if (argc == 1)
	{
		shell_init(&vars, env);
		while (1)
		{
			interpret(&input, &vars);
			if (input[0] == '.' || input[0] == '/')
				path_execution(&vars);
			else
				simple_execution(&vars);
			free(input);
		}
	}
	else
		printf("[Error] minishell doesn't need argument(s)\n");
	return (0);
}
