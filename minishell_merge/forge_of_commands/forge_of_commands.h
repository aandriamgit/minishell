/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_of_commands.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:01:56 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/12 13:23:48 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_init/shell_init.h"
#include "../utils/utils.h"

void		init_stderr(t_stderr_a *stderr_a);
void		custom_prompt(t_vars *vars, t_pipe_a **cmd_a);
t_pipe_a	*convert_t_pipe_a(t_pipe *cmd);
void		heredoc_supremacy(t_pipe_a *pipe_a, t_vars *vars);
void		exec_t_pipe_a(t_pipe_a *pipe_a, t_vars *vars);