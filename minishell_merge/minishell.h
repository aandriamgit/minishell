/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:01:24 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/08 15:41:34 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/lib.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// list

typedef struct s_list
{
	char					*parameter;
	int						assignation;
	struct s_list			*next;
}							t_list;

// env
t_list						*duplicate_env(char **env);
void						display_env_list(t_list *list);

// simple_export
void						display_export_list(t_list **list);
void						simple_export(t_list *env);
t_list						*duplicate_export(t_list *env);

// export_with_arg
int							testing_arg(char *str);
void						export_with_arg(t_list **env, char *arg);

// display_export
void						mini_display(char *tmp);
void						display_export_list(t_list **list);

// check_export
int							compare_content(char *parameter, char *str);
int							check_list(t_list **env, char *str);

// unset
int							unset(t_list **environement, char *str);
int							check_by_list(t_list **env, char *str);
int							compare_param(char *parameter, char *str);

// libft
char						*ft_substr(char *str, int start, int end);
int							ft_strlen(const char *str);
int							ft_strcmp(char *first, char *second);
char						**ft_split(char *s, char c);

// list
int							check_assignation(char *str);
t_list						*creat_bloc_of_list(char *str);
void						creat_chain_of_list(t_list **old_list,
								t_list *new_list);
void						display_list(t_list **list);
void						ordered_list(t_list **list);

// parsing and vars
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

// aandriam
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
char						*get_next_line(int fd);
char						*nice_prompt_lol(void);

#endif
