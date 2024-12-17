/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:33:52 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/16 13:04:24 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_putstr_fd_a(char *s, int fd);
int		ft_strncmp_a(const char *s1, const char *s2);
char	**ft_split_a(char const *s, char c);
char	*ft_substr_a(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_a(const char *s);
char	*ft_strdup_a(const char *s);
char	*ft_strjoin_a(char const *s1, char const *s2);
char	*ft_itoa_a(int n);
char	*ft_strrchr_a(const char *s, int c);
void	ft_putnbr_fd_a(int n, int fd);
void	ft_putchar_fd_a(char c, int fd);
char	*ft_strjoin_free_a(char *s1, char *s2);
int		ft_isdigit_a(int c);
int		ft_atoi_a(const char *nptr);
int		ft_random_int(char *str);
