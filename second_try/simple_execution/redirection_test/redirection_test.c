/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:52:58 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/16 13:52:39 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection_test.h"

void	first_test(t_vars *vars)
{
	char			**big_param;
	t_pipe			*test_pipe;
	char			*cmd;
	t_redirection	*redir;

	big_param = malloc(sizeof(char **) * 2);
	if (!big_param)
		return ;
	big_param[0] = ft_strdup("cat");
	big_param[1] = NULL;
	test_pipe->next = NULL;
	redir = gen_redir("<", "input.txt", NULL);
	test_pipe->cmd = gen_cmd(cmd, big_param, redir, NULL);
	exec_t_pipe(test_pipe);
}
