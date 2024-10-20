/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_test.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:31 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/20 11:36:38 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../simple_execution.h"

t_command		*gen_cmd(char *cmd, char **big_param, void *redir, void *next);
t_redirection	*gen_redir(char *type, char *file, void *next);
void			exec_t_pipe(t_pipe *test_pipe);
void			free_t_pipe(t_pipe *test_pipe);
