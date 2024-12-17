/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:49:49 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/16 15:01:50 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libft/libft.h"

typedef struct s_list
{
	char *cmd;
	char *parameter;
	char *arg;
	int size_arg;
	int assignation;
	struct s_list *next;
} t_list;

typedef struct s_redir
{
	char *type;
	char *file;
	struct s_redir *next;
} t_redir;

typedef struct s_cmd
{
	char *cmd;
	char **arg;
	//struct s_cmd *next;
} t_cmd;

typedef struct s_pipe 
{
	t_redir *redir;
	t_cmd	*cmd;
	struct s_pipe *next;
}t_pipe;

void check_input(char **str);
int	count(char *str);
char **ft_split_na(char *str);
void skip(char *str, int *i);
char **split_expand(char *str);
char *ft_strjoin_space(char ***str);
void	simple_expend(char **str, t_list *env);
void	modify(char **str, t_list *env_cp);
char **simple_split(char *str, char c);
void formating(char **str, t_list *env_cp);
char *join_with_space(char **str);
char *join_no_space(char **str);
void	free_split(char ***str);
t_redir	*redirection(char **str);
t_cmd	*make_cmd(char **str);
t_cmd	*cmd(char **str);
t_pipe	*creat_bloc_pipe(char **str);
void	creat_chain_of_pipe(t_pipe **old_list, t_pipe *new_list);
t_pipe	*gen_pipe(char **str);
void	ex_quote(char **str, t_list *env_cp);
char **split_pipe(char *str, char c);
int	check_quotes(char *str);
void	rm_quote(char **str);
void	free_pipe(t_pipe **x);
//builtings
t_list	*duplicate_env(char **env);
void	display_env_list(t_list *list);
int check_list(t_list **env, char *str);
void display_export_list(t_list **list);
void	export_with_arg(t_list **env, char *arg);
void	simple_export(t_list *env);
int	unset_p(t_list **environement, char *str);

//list
t_list	*creat_bloc_of_list(char *str);
int check_assignation(char *str);
void creat_chain_of_list(t_list **old_list, t_list *new_list);
void display_list(t_list **list);
void	ordered_list(t_list **list);
t_redir	*creat_bloc_redir(char *type, char *file);
void creat_chain_of_redir(t_redir **old_list, t_redir *new_list);

void	check_expand(char **str, t_list *cp_env);
void	expend(char **str, t_list *env);
char	*ft_strjoin_p(char ***str);
int	count_x(char *str);

//display
void	display_list_p(t_list *list);
void	display_env_p(t_list *list);
void	display_export_p(t_list *list);
void	sort_list(t_list **list);
void	duplicate_list(t_list **old_list, t_list *new_list);
t_list	*duplicate(t_list *list);
//char	**ft_split(char const *s, char c);
#endif
