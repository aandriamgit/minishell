/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:42:11 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/12 17:11:32 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef SIMPLE_EXECUTION_H
# define SIMPLE_EXECUTION_H

t_pipe			*generate_redir(char *cmd, char *type, char *dir);
void			test_exec_redir(t_pipe *lol, t_vars *vars);
t_command		*cmd_gen_redir(char *input);
t_redirection	*end_of(char *dir);
t_redirection	*redir_gen_o(char *cmd, char *type, char *dir);
void			input_redir_test(t_pipe *lol, char *log_dir);
void			here_doc_test(t_pipe *lol);
void			output_redir_test(t_pipe *lol);
void			append_redir_test(t_pipe *lol);
int				file_exist(char *dir);
char			*take_input(char *dir);

#endif
