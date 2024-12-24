/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe_a.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:09:25 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/24 14:08:42 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../forge_of_commands.h"
#include <errno.h>

void	exec_built_ins_w(t_command_a *cmd, t_vars *vars);
void	handle_redir(t_redirection_a *redir, t_vars *vars, int *flag);
void	built_ins_n(t_command_a *cmd, t_vars *vars);
void	gen_pid_a(t_pipe_a *pipe_a, t_vars *vars);
void	path_no_pipe(t_pipe_a *pipe_a, t_vars *vars);
int		handle_child_exit_no_pipe(pid_t child_pid, t_vars *vars);
void	path_w_pipe(t_pipe_a *pipe_a, t_vars *vars);
int		ambiguous_redirect(char **file, t_vars *vars);
