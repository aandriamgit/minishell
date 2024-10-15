/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:13:12 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/15 18:02:42 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "get_next_line/get_next_line.h"
# include "lib/lib.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
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

void						vars_init(t_vars *vars, char **env);
void						big_param_init(char ***big_param, t_vars vars);
void						add_prev_history(t_vars *vars);
void						exec_big_param(char **big_param);
void						exit_protocol(t_vars *vars, char **input);
char						*nice_prompt(void);
void						ft_add_history(char *input, t_vars *vars);

#endif
