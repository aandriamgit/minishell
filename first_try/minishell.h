/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:33:19 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/15 16:07:47 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lib/lib.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <termios.h>
# include <time.h>
# include <unistd.h>

typedef struct s_command
{
	char					*cmd;
	char					**args;
}							t_command;

typedef struct s_redirection
{
	char					*type;

	struct s_command		*cmd;
	struct s_redirection	*next;
}							t_redirection;

typedef struct s_pipe
{
	struct s_redirection	*redirection;
	struct s_pipe			*next;
}							t_pipe;

typedef struct s_vars
{
	char					*log_dir;
	char					*history_dir;
	char					*input;
	char					**env;
	char					*env_dir;
	char					*env_dir_name;
	struct s_pipe			*pipe;
}							t_vars;

int							number_of_line(int fd);
char						*join_them(char *new_buff, char *temp);
char						have_nl(char *buffer);
char						*only_readable(char *buffer);
void						ft_add_history(char *input, t_vars *vars);
void						big_param_init(char ***big_param, t_vars vars);
void						terminate_shell_init(char **big_param);
void						vars_init(t_vars *vars, char **env);
void						fork_mkdir(char **big_param);
void						exit_protocol(t_vars *vars, char **input);
int							have_pipe(t_vars *vars);
void						no_pipe_exec(t_vars *vars);
void						pipe_exec(t_vars *vars);
char						**ft_split(char const *s, char c);
char						*test(char *path, char *input);
void						fork_exec_nopipe(char *path, char **big_param,
								t_vars *vars);
void						set_non_canonical_mode(void);
void						free_res(char ***res);
char						*get_next_line(int fd);
char						*join_them(char *new_buff, char *temp);
char						have_nl(char *buffer);
void						add_prev_history(t_vars *vars);
char						*nice_prompt(void);
int							is_special_cmd(t_vars *vars);
void						terminate_nopipe_o(char *path, char **big_param,
								t_vars *vars);
void						terminate_nopipe(char *path, char **big_param,
								t_vars *vars);
void						exec_cd(t_vars *vars);
void						exec_export(t_vars *vars);
void						exec_unset(t_vars *vars);
void						exec_env(t_vars *vars);
void						exec_echo(t_vars *vars);
void						creat_env_dir(t_vars *vars);
t_pipe						*parsing_test(void);
void						cmd_test(t_vars *vars);
void						use_as_input(char **buff, t_pipe *v_one);
char						*get_output(t_pipe *v_one, t_vars *vars);
int							is_redirection(t_vars vars);
void						exec_redirection(t_vars *vars);
void						p_test(t_vars *vars);
void						redir_test(t_vars *vars);
void						s_o_test(t_vars *vars);
void						append_test(t_vars *vars);
void						s_o_errors_test(t_vars *vars);

#endif
