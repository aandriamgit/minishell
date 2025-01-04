/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:01:24 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/04 16:53:16 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "forge_of_commands/forge_of_commands.h"
# include "minishell_dlc/libft/libft.h"
# include "minishell_dlc/parsing.h"
# include "shell_init/shell_init.h"
# include "utils/utils.h"

t_list	*duplicate_env(char **env);
void	display_env_list(t_list *list);

void	display_export_list(t_list **list);
void	simple_export(t_list *env);
t_list	*duplicate_export(t_list *env);

int		testing_arg(char *str);
void	export_with_arg(t_list **env, char *arg);

void	mini_display(char *tmp);
void	display_export_list(t_list **list);

int		compare_content(char *parameter, char *str);
int		check_list(t_list **env, char *str);

int		unset(t_list **environement, char *str);
int		check_by_list(t_list **env, char *str, t_list *tmp, t_list *prev);
int		compare_param(char *parameter, char *str);

int		check_assignation(char *str);
t_list	*creat_bloc_of_list(char *str);
void	creat_chain_of_list(t_list **old_list, t_list *new_list);
void	display_list(t_list **list);
void	ordered_list(t_list **list);

void	vars_init(t_vars *vars, t_list **env_cpy);
void	big_param_init(char ***big_param, t_vars vars);
void	add_prev_history(t_vars *vars);
void	exec_big_param(char **big_param);
int		is_special(t_vars *vars);
void	pipe_test(t_vars *vars);
void	redirection_test(t_vars *vars);
char	*get_next_line(int fd);
char	*nice_prompt_lol(void);

void	handler_child(int signum);
#endif
