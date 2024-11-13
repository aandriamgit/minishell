/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:16:14 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 09:41:44 by aandriam         ###   ########.fr       */
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

void	ft_free_all(char ***argv);
void	ft_execve(char *cmd, char **argv);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2);

char	*ft_substr(const char *str, int start, int end);
int		ft_strlen(const char *str);
int		ft_strcmp(char *first, char *second);
char	**ft_split(const char *s, char c);

#endif
