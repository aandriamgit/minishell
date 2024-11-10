/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:46:17 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/10 17:31:34 by aandriam         ###   ########.fr       */
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

typedef struct s_list
{
	char					*parameter;
	int						assignation;
	struct s_list			*next;
}							t_list;

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

typedef struct s_pipe
{
	t_command				*cmd;
	struct s_pipe			*next;
}							t_pipe;

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
	struct s_pipe_a			*next;
	struct s_pipe_a			*prev;
}							t_pipe_a;

typedef struct s_stderr
{
	char					*dir;
	int						fd;
}							t_stderr_a;

typedef struct s_vars
{
	char					*log_dir;
	char					*history_dir;
	char					*input;
	t_stderr_a				*stderr_a;
	t_list					*env;
}							t_vars;

char						*test(char *path, char *cmd);

#endif
