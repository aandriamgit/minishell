/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:50 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/19 16:04:00 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "interpret/interpret.h"
#include "minishell.h"
#include "minishell_dlc/parsing.h"

static void	handler(int signum)
{
	char	buffer[1024];
	char	*lol;
	char	*res;
	char	*tmp;

	getcwd(buffer, 1024);
	tmp = ft_strjoin_a("\033[38;2;166;227;161m╭\033[38;2;148;226;213m ",
			buffer);
	res = ft_strjoin_a(tmp, "\033[38;2;137;180;250m  \033[0m");
	lol = ft_strjoin_free_a(res, "\n\001\033[38;2;243;139;168m\002\001╰\002");
	lol = ft_strjoin_free_a(lol, "\001\002\001\033[0m\002 ");
	if (signum == SIGINT)
	{
		upload_exit_code(130);
		printf("\n%s", lol);
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

static void	shell_init(t_vars *vars, t_list **env_cpy, char **input, char **env)
{
	char	**big_param;

	*input = NULL;
	*env_cpy = duplicate_env(env);
	vars_init(vars, env_cpy);
	vars->input = NULL;
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
	vars->input = ft_strdup_a(*input);
	free(prompt);
	if (*input == NULL)
	{
		ft_putstr_fd_a("exit\n", 1);
		exit_protocol(vars, input, 0);
	}
	if (access(vars->history_dir, F_OK) == 0)
		ft_add_history(*input, vars);
	else
		exit_protocol(vars, input, 127);
	if (unclosed_quote(input, vars))
		show_errors(vars);
	else
	{
		check_input(input);
		formating(input, vars->env);
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
		if (ft_strncmp_a(vars->input, "custom_prompt") == 0)
			custom_prompt(vars, &pipe_a);
		if (ft_strncmp_a(vars->input, "debug_mode_reboot") == 0)
			reboot_prompt(vars, &pipe_a);
		if (ft_strncmp_a(vars->input, "custom_perror") == 0)
			custom_perror(vars, &pipe_a);
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
	if (argc == 1)
	{
		shell_init(&vars, &env_cpy, &input, env);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
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
		perror("[minishell] too many argument's'");
		return (1);
	}
	return (0);
}
