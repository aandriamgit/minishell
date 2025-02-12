/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:46:17 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/04 16:53:23 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_INIT_H
# define SHELL_INIT_H

# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_redirection
{
	char					*type;
	char					*file;
	struct s_redirection	*next;
}							t_redirection;

typedef struct s_command
{
	char					*cmd;
	char					**args;
	t_redirection			*redir;
	struct s_command		*next;
}							t_command;

typedef struct s_redirection_a
{
	char					*type;
	char					*file;
	struct s_redirection_a	*next;
}							t_redirection_a;

typedef struct s_command_a
{
	char					*cmd;
	char					**args;
	t_redirection_a			*redir;
	struct s_command_a		*next;
}							t_command_a;

typedef struct s_pipe_a
{
	t_command_a				*cmd;
	pid_t					pid;
	struct s_pipe_a			*next;
	struct s_pipe_a			*prev;
}							t_pipe_a;

typedef struct s_list
{
	char					*cmd;
	char					*parameter;
	char					*arg;
	int						size_arg;
	int						assignation;
	struct s_list			*next;
}							t_list;

typedef struct s_redir
{
	char					*type;
	char					*file;
	struct s_redir			*next;
}							t_redir;

typedef struct s_cmd
{
	char					*cmd;
	char					**arg;
}							t_cmd;

typedef struct s_pipe
{
	t_redir					*redir;
	t_cmd					*cmd;
	struct s_pipe			*next;
}							t_pipe;

typedef struct s_vars
{
	char					*log_dir;
	char					*history_dir;
	char					*input;
	char					*heredoc_dir;
	char					*quote_dir;
	char					*exit_code_dir;
	char					*stderr_a;
	char					*stderr_log;
	char					**env_cpy;
	char					*save_heredoc;
	int						err_nbr;
	int						custom_flag;
	int						custom_prompt;
	int						exit_code_int;
	int						*pipe_fd_err;
	t_list					*env;
	t_pipe_a				*t_pipe_a;
	t_pipe					*cmd;
}							t_vars;

typedef struct s_redir_fd
{
	char					*type;
	char					*file;
	int						fd;
	struct s_redir_fd		*next;
}							t_redir_fd;

char						*test(char *path, char *cmd);
void						creat_files(t_vars *vars);
void						handler(int signum, siginfo_t *s_siginfo,
								void *context);

#endif
