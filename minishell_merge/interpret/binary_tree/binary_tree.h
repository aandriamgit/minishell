/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:45:26 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/09 13:46:12 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell_init/shell_init.h"

t_pipe			*binary_tree(char *format_cmd);
t_command		*creat_cmd(char *command);
t_redirection	*down_redirection(char *cmd_with_redirection);
t_pipe			*down_pipe(char *cmd_with_pipe);
char			**take_type(char *cmd);
