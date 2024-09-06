/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:24:06 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/06 09:33:06 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 1024

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_readline(void);
void	ft_putstr(char *str, int fd);
void	ft_readline_history(char *buffer, char **tmp);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
int		read_size_buffer(char *str);
int		simple_read_size(char *str);
void	ft_putstr(char *str, int fd);
int		ft_strncmp(const char *s1, const char *s2);

#endif
