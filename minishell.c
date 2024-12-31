/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:50 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/31 11:11:12 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "interpret/interpret.h"
#include "minishell.h"
#include "minishell_dlc/parsing.h"
#include <errno.h>
#include <signal.h>
#include <string.h>

static void	shell_init(t_vars *vars, t_list **env_cpy, char **input, char **env)
{
	char				**big_param;
	struct sigaction	s_sigint;

	s_sigint.sa_sigaction = handler;
	s_sigint.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigint.sa_mask);
	signal(SIGQUIT, SIG_IGN);
	sigaction(SIGINT, &s_sigint, NULL);
	*input = NULL;
	*env_cpy = duplicate_env(env);
	vars_init(vars, env_cpy);
	vars->input = NULL;
	vars->cmd = NULL;
	vars->env_cpy = env;
	vars->cmd = NULL;
	big_param_init(&big_param, *vars);
	if (access(vars->log_dir, F_OK) == 0)
		ft_free_tab(&big_param);
	else
		exec_big_param(big_param);
	creat_files(vars);
	if (big_param)
		ft_free_tab(&big_param);
}

static void	interpret(char **input, t_vars *vars, t_pipe **cmd)
{
	char	*prompt;

	prompt = nice_prompt(vars);
	*input = readline(prompt);
	if (!vars->exit_code_int)
		vars->exit_code_int = download_exit_code(vars);
	vars->input = ft_strdup_a(*input);
	free(prompt);
	if (*input == NULL)
	{
		ft_putstr_fd_a("exit\n", 1);
		exit_protocol(vars, input, vars->exit_code_int);
	}
	if (access(vars->history_dir, F_OK) == 0)
		ft_add_history(*input, vars);
	else
		exit_protocol(vars, input, 127);
	if (unclosed_quote(input, vars) || unclosed_pipe(input, vars))
		show_errors(vars);
	else
	{
		check_input(input);
		formating(input, vars->env, vars);
		*cmd = gen_pipe(input);
		vars->cmd = *cmd;
	}
}

static void	forge_of_commands(t_pipe **cmd, t_vars *vars)
{
	t_pipe_a	*pipe_a;

	if (vars->input)
	{
		pipe_a = convert_t_pipe_a(*cmd);
		init_stderr(vars);
		if (ft_strncmp_a(vars->input, "debug_custom_prompt") == 0)
			custom_prompt(vars, &pipe_a);
		if (ft_strncmp_a(vars->input, "debug_mode_reboot") == 0)
			reboot_prompt(vars, &pipe_a);
		else
		{
			heredoc_supremacy(pipe_a, vars);
			exec_t_pipe_a(pipe_a, vars);
			terminus((void *)&pipe_a, vars);
			if (vars->cmd)
			{
				free_pipe(cmd);
				vars->cmd = NULL;
			}
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list	*env_cpy;
	t_vars	vars;
	t_pipe	*cmd;
	char	*input;

	(void)argv;
	cmd = NULL;
	if (argc == 1)
	{
		shell_init(&vars, &env_cpy, &input, env);
		while (1)
		{
			interpret(&input, &vars, &cmd);
			forge_of_commands(&cmd, &vars);
			if (vars.input)
				free(vars.input);
		}
	}
	else
	{
		errno = 22;
		perror("[minishell]");
		return (1);
	}
	return (0);
}
