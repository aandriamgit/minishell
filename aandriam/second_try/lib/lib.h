/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:16:14 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/08 10:58:38 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	ft_execve(char *cmd, char **argv);
char	**ft_split(char const *s, char c);
void	ft_free_all(char ***argv);
char	*ft_strrchr(const char *s, int c);
void	ft_perror(char *file, char *str);
char	*ft_itoa(int n);
void	ft_perror_fork(char *file, char *str);

#endif
