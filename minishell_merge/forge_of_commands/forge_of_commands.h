/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_of_commands.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:01:56 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/10 16:48:52 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_init/shell_init.h"
#include "../utils/utils.h"

void		init_stderr(t_stderr_a *stderr_a);
void		custom_prompt(t_vars *vars, t_pipe_a **cmd_a);
t_pipe_a	*convert_t_pipe_a(t_pipe *cmd);
