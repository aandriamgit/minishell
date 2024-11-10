/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:50 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/10 18:18:47 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signum)
{
	char	*res;
	char	*tmp;
	char	buffer[1024];

	getcwd(buffer, 1024);
	tmp = ft_strjoin("\033[38;2;166;227;161m╭\033[38;2;148;226;213m ", buffer);
	res = ft_strjoin(tmp, "\033[38;2;137;180;250m  \033[0m");
	free(tmp);
	if (signum == SIGINT)
	{
		printf("\n%s\n", res);
		free(res);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	shell_init(t_vars *vars, t_list **env_cpy, char **input, char **env)
{
	char	**big_param;

	*input = NULL;
	*env_cpy = duplicate_env(env);
	vars_init(vars, env_cpy);
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
}

void	interpret(char **input, t_vars *vars, t_pipe *cmd)
{
	char	*prompt;

	prompt = nice_prompt();
	*input = readline(prompt);
	free(prompt);
	if (*input == NULL)
		exit_protocol(vars, input);
	if (access(vars->history_dir, F_OK) == 0)
		ft_add_history(*input, vars);
	else
	{
		open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
		ft_add_history(*input, vars);
	}
	unclosed_quote(input);
	vars->input = *input;
	formating(input);
}

void	forge_of_commands(t_pipe *cmd, t_vars *vars)
{
	t_pipe_a	*pipe_a;

	pipe_a = convert_t_pipe_a(cmd);
	init_stderr(vars->stderr_a);
	if (ft_strncmp_a(vars->input, "custom_prompt") == 0)
		custom_prompt(vars, &pipe_a);
	if (pipe_a->next)
		multi_pipe_exec(vars, pipe_a);
	else
		mono_pipe_exec(vars, pipe_a);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*env_cpy;
	t_vars	vars;
	t_pipe	cmd;
	char	*input;

	(void)argv;
	if (argc == 1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
		shell_init(&vars, &env_cpy, &input, env);
		while (1)
		{
			interpret(&input, &vars, &cmd);
			forge_of_commands(&cmd, &vars);
		}
	}
	else
	{
		perror("[minishell] too many argument's'");
		return (1);
	}
	return (0);
}
