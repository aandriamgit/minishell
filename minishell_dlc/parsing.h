/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:49:49 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/26 18:28:38 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "./libft/libft.h"
# include "../shell_init/shell_init.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <unistd.h>


void				check_input(char **str);
int					count(char *str);
char				**ft_split_na(char *str);
void				skip(char *str, int *i);
char				**split_expand(char *str);
char				*ft_strjoin_space(char ***str);
void				simple_expend(char **str, t_list *env);
void				modify(char **str, t_list *env_cp);
char				**simple_split(char *str, char c);
void				formating(char **str, t_list *env_cp, t_vars	*vars);
char				*join_with_space(char **str);
char				*join_no_space(char **str);
void				free_split(char ***str);
t_redir				*redirection(char **str);
t_cmd				*make_cmd(char **str);
t_cmd				*cmd(char **str);
t_pipe				*creat_bloc_pipe(char **str);
void				creat_chain_of_pipe(t_pipe **old_list, t_pipe *new_list);
t_pipe				*gen_pipe(char **str);
void				ex_quote(char **str, t_list *env_cp, t_vars	*vars);
char				**split_pipe(char *str, char c);
int					check_quotes(char *str);
void				rm_quote(char **str);
void				free_pipe(t_pipe **x);
char				**split_quote(char *str, char c);
void				free_node_list(t_list **list);
char				*ft_getenv(char *str, t_list *env);
int					check_bloc(char *str);
int					check_her(char *s1, char *s2, int flag);
void				skip_x(int *i, char *str, char c);
char				**split_expand_1(char *str);
char				**split_take_quote(char *str, char c);
void	formating_quote(char **str, t_list *env_cp, t_vars	*vars);
// builtings
t_list				*duplicate_env(char **env);
void				display_env_list(t_list *list);
int					check_list(t_list **env, char *str);
void				display_export_list(t_list **list);
void				export_with_arg(t_list **env, char *arg);
void				simple_export(t_list *env);
int					unset_p(t_list **environement, char *str);

// list
t_list				*creat_bloc_of_list(char *str);
int					check_assignation(char *str);
void				creat_chain_of_list(t_list **old_list, t_list *new_list);
void				display_list(t_list **list);
void				ordered_list(t_list **list);
t_redir				*creat_bloc_redir(char *type, char *file);
void				creat_chain_of_redir(t_redir **old_list, t_redir *new_list);

void				check_expand(char **str, t_list *cp_env, t_vars	*vars);
char				*ft_strjoin_p(char ***str);
int					count_x(char *str);

// display
void				display_list_p(t_list *list);
void				display_env_p(t_list *list);
void				display_export_p(t_list *list);
void				sort_list(t_list **list);
void				duplicate_list(t_list **old_list, t_list *new_list);
t_list				*duplicate(t_list *list);
void				modify_str(char **str, t_list *env_cp, t_vars *vars);
// char	**ft_split(char const *s, char c);
#endif
