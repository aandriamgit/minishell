/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:13:12 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/16 13:23:23 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "get_next_line/get_next_line.h"
# include "lib/lib.h"

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

typedef struct s_vars
{
	char					*log_dir;
	char					*history_dir;
	char					*input;
	char					**env;
}							t_vars;

void						vars_init(t_vars *vars, char **env);
void						big_param_init(char ***big_param, t_vars vars);
void						add_prev_history(t_vars *vars);
void						exec_big_param(char **big_param);
void						exit_protocol(t_vars *vars, char **input);
char						*nice_prompt(void);
void						ft_add_history(char *input, t_vars *vars);
int							is_special(t_vars *vars);
void						pipe_test(t_vars *vars);
void						redirection_test(t_vars *vars);

#endif
