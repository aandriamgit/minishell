/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:50 by mravelon          #+#    #+#             */
/*   Updated: 2024/10/17 17:11:03 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void handler(int signum)
{
		char	*lol;

		lol = nice_prompt_lol();
		if (signum == SIGINT)
		{
			printf("\n%s\n", lol);
			free(lol);
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
		}
}

void	shell_init(t_vars *vars, t_list **env_cpy, char	**env)
{
	char	**big_param;
	
	*env_cpy = NULL;
	*input = NULL;
	vars_init(vars, env);
	big_param_init(&big_param, *vars);
	if (access(vars->log_dir, F_OK) == 0)
	{
		ft_free_all(&big_param);
		if (access(vars->history_dir, F_OK) == 0)
			add_prev_history(vars);
		else
			open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
		return ;
	}
	else
		exec_big_param(big_param);
	open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
	add_prev_history(vars);
	ft_free_all(&big_param);
	*env_cpy = duplicate_env(env);
}

void	interpret(char **input, t_vars *vars, t_pipe *cmd)
{
	char	*prompt;

	prompt = nice_prompt();
	*input = readline(prompt);
	if (*input == NULL)
		exit_protocol(vars, input);
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

int	main(int	argc, char	**argv, char	**env)
{
	t_list 	*env_cpy;
	t_vars 	vars;
	t_pipe	cmd;
	char 	*input;
	
	(void)argv;
	if (argc == 1)
	{		
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
		shell_init(&vars, &env_cpy, env);
		while (1)
		{
			interpret(&input, &vars, &cmd);
		}
	}
	else
	{
		perror("minishell doesn't need argument's'");
		return (1);
	}
	return (0);
}
