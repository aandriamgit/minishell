/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:37:04 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/22 17:24:04 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_tree
{
	char *cmd;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

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

//tree function
t_tree *creat_leaf(char *cmd);
void right_chain_of_leaf(t_tree **chained_leaf, t_tree *leaf);
void left_chain_of_leaf(t_tree **chained_leaf, t_tree *leaf);
t_tree *creat_leaf(char *cmd);

//binary_tree


#endif

