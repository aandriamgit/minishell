/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_of_commands.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:01:56 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/31 15:06:05 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_init/shell_init.h"
#include "../utils/utils.h"

void		init_stderr(t_vars *vars);
void		custom_prompt(t_vars *vars, t_pipe_a **cmd_a);
t_pipe_a	*convert_t_pipe_a(t_pipe *cmd);
void		heredoc_supremacy(t_pipe_a **pipe_a, t_vars *vars, int *flag);
void		exec_t_pipe_a(t_pipe_a *pipe_a, t_vars *vars);
void		terminus(void **pipe_a, t_vars *vars);
void		show_errors(t_vars *vars);
void		reboot_prompt(t_vars *vars, t_pipe_a **pipe_a);
