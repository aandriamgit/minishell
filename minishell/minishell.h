/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:24:06 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/05 17:01:46 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
#define MINISHELL_H
#define BUFFER_SIZE 1024

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_readline();
void 	ft_putstr(char *str, int fd);
void	ft_readline_history(char *buffer, char **tmp);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
int		read_size_buffer(char *str);
int 	simple_read_size(char *str);
void	ft_putstr(char *str, int fd);
int		ft_strncmp(const char *s1, const char *s2);

#endif
