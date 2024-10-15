/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:05 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/11 10:19:27 by aandriam         ###   ########.fr       */
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
		terminate_shell_init(big_param);
		if (access(vars->history_dir, F_OK) == 0)
			add_prev_history(vars);
		else
			open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
		return ;
	}
	else
		fork_mkdir(big_param);
	open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
	add_prev_history(vars);
	terminate_shell_init(big_param);
	// creat_env_dir(vars);
}

void	interpret(char **input, t_vars *vars)
{
	char	*prompt;

	prompt = nice_prompt();
	*input = readline(prompt);
	free(prompt);
	if (access(vars->history_dir, F_OK) == 0)
		ft_add_history(*input, vars);
	else
	{
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
	if (ft_strncmp(vars->input, "pipe_test") == 0)
		cmd_test(vars);
	else if (ft_strncmp(vars->input, "redirection_test") == 0)
		cmd_test(vars);
	else if (have_pipe(vars))
		pipe_exec(vars);
	else
		no_pipe_exec(vars);
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
