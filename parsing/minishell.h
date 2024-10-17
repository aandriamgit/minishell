/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:37:04 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/26 15:05:34 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_command
{
	char *cmd;
	char *option;
	char **arguments;
} t_command;


typedef struct s_redirection
{
	char *type_of_redirection;

	struct s_command *cmd;
	struct s_redirection *next;
} t_redirection;


typedef struct s_pipe
{
	struct s_redirection *redirection;
	struct s_pipe *next;
} t_pipe;

//formating function
char *formating(char *input);
int check_quote(char *input);

//libft function
int ft_strncmp(const char *s1, const char *s2);
int ft_strlen(const char *str);
char **ft_split(char const *s, char c);
int main(int argc, char **argv);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(const char *s);
char **cheated_split(char *input);
char *creat_bloc(int start, int end, char *input);

//binary_tree
t_pipe *binary_tree(char *format_cmd);
t_command *creat_cmd(char *command);
t_redirection *down_redirection(char *cmd_with_redirection);
t_pipe	*down_pipe(char *cmd_with_pipe);
char **take_type(char *cmd);
#endif

