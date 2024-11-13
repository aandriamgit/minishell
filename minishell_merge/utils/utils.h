/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:21:46 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 09:56:28 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../shell_init/shell_init.h"
#include "lib/lib.h"
#include <sys/stat.h>

void			ft_perror_row(char *file, char *str, t_vars *vars);
void			ft_perror_fork(char *file, char *str, t_vars *vars);
void			ft_execve_row(char *cmd, char **argv);
void			ft_execve_fork(char *cmd, char **argv);
void			ft_free_tab(char ***argv);
void			ft_free_t_list(t_list **env);
t_command_a		*gen_cmd(char *cmd, char **big_param, void *redir, void *next);
t_pipe_a		*gen_pipe_a(t_command_a *cmd, t_pipe_a *prev, t_pipe_a *next);
t_redirection_a	*gen_redir(char *type, char *file, void *next);
void			add_redir_end(t_redirection_a **res, t_redirection_a **to_add);
void			add_pipe_end(t_pipe_a **p_test, t_pipe_a **to_add);
void			ft_print_pipe_a(t_pipe_a *tmp);
void			ft_execve_path(char *cmd, char **argv, t_vars *vars);
