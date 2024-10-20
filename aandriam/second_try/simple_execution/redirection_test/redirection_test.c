/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:52:58 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/20 12:31:15 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection_test.h"

void	first_test(char *cmd, char *type, char *file)
{
	char			**big_param;
	t_pipe			*test_pipe;
	t_redirection	*redir;

	big_param = malloc(sizeof(char **) * 2);
	if (!big_param)
		return ;
	test_pipe = malloc(sizeof(t_pipe));
	if (!test_pipe)
		return ;
	big_param[0] = cmd;
	big_param[1] = NULL;
	redir = gen_redir(type, file, NULL);
	test_pipe->cmd = gen_cmd(cmd, big_param, redir, NULL);
	test_pipe->next = NULL;
	test_pipe->prev = NULL;
	exec_t_pipe(test_pipe);
	free_t_pipe(test_pipe);
	free(test_pipe);
}
