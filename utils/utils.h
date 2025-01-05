/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:21:46 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/05 13:08:48 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../shell_init/shell_init.h"
#include "lib/lib.h"
#include <sys/stat.h>

void			ft_perror_soft(char *file, char *str, t_vars *vars, int nbr);
void			ft_perror_exit(char *file, char *str, t_vars *vars, int nbr);
void			ft_execve_row(char *cmd, char **argv);
void			ft_execve_fork(char *cmd, char **argv);
void			ft_free_tab(char ***argv);
void			ft_free_t_list(t_list **env);
void			ft_free_t_pipe_a(t_pipe_a *pipe_a);
void			ft_free_t_pipe_again(t_pipe_a **p_test);
t_command_a		*gen_cmd(char *cmd, char **big_param, void *redir, void *next);
t_pipe_a		*gen_pipe_a(t_command_a *cmd, t_pipe_a *prev, t_pipe_a *next);
t_redirection_a	*gen_redir(char *type, char *file, void *next);
void			add_redir_end(t_redirection_a **res, t_redirection_a **to_add);
void			add_pipe_end(t_pipe_a **p_test, t_pipe_a **to_add);
void			ft_print_pipe_a(t_pipe_a *tmp);
void			ft_execve_path(t_pipe_a *pipe_a, char *cmd, char **argv,
					t_vars *vars);
char			*get_file_dir(char *file);
char			*test_path(char *path, char *input);
void			upload_exit_code(int nbr);
int				download_exit_code(t_vars *vars);
int				cmd_check(char *cmd, t_vars *vars);
void			ft_execve_path_kill(t_pipe_a *pipe_a, char *cmd, char **argv,
					t_vars *vars);
void			ft_perror_redir(char *file, t_vars *vars, int err, int nbr);
int				gen_fd(t_vars *vars);
int				count_files_in_directory(const char *directory);
int				custom_error(char *file, char *str, t_vars *vars);
void			custom_cmd_not_found(char *file, char *str, t_vars *vars,
					int err);
void			custom_is_a_dir(char *file, char *str, t_vars *vars, int err);
void			custom_nosuchfileordir(char *file, char *str, t_vars *vars,
					int err);
void			custom_permission_denied(char *file, char *str, t_vars *vars,
					int err);
void			close_all_fds(void);
int				can_custom(void);
char			*get_magic_prompt(void);
void			extra_check_void_pipe(char *str, int *i);
char			*emergency_prompt_lol(void);
