/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_t_pipe_a.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:46:25 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 08:29:34 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../forge_of_commands.h"

void	handle_cmd(t_pipe_a *pipe_a, int input, int output, t_vars *vars);
char	*get_file_dir(char *file);
int		is_built_ins(t_command_a *cmd);
void	exec_built_ins_w(t_command_a *cmd, t_vars *vars);
void	exec_built_ins_n(t_command_a *cmd, t_vars *vars);
void	handle_redir(t_redirection_a *redir, t_vars *vars);
