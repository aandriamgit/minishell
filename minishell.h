/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:33:19 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/22 13:33:39 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_vars
{
	char	*log_dir;
	char	*history_dir;
}			t_vars;

void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2);
int			number_of_line(int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*only_readable(char *buffer);
char		*ft_readline(char *prompt);
void		ft_add_history(char *input, t_vars vars);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
void		big_param_init(char ***big_param, t_vars vars);
void		terminate_shell_init(char **big_param);
void		vars_init(t_vars *vars);
void		fork_mkdir(char **big_param);
void		exit_protocol(t_vars *vars, char **input);

#endif
