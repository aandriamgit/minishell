/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_redir_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:45:56 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/22 10:07:25 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../redirection_test.h"

static void	free_them(char **cmd, char **first_redir, char **next_redir)
{
	free(*cmd);
	free(*first_redir);
	free(*next_redir);
}

void	exec_combined_redir(char *cmd, char *first_redir, char *next_redir)
{
	char			**first;
	char			**big_param;
	char			**next;
	t_redirection	*redir;
	t_pipe			*test_pipe;

	first = ft_split(first_redir, ' ');
	next = ft_split(next_redir, ' ');
	big_param = ft_split(cmd, ' ');
	redir = gen_redir(first[0], first[1], gen_redir(next[0], next[1], NULL));
	test_pipe = malloc(sizeof(t_pipe));
	test_pipe->cmd = gen_cmd(big_param[0], big_param, redir, NULL);
	test_pipe->next = NULL;
	test_pipe->prev = NULL;
	exec_t_pipe(test_pipe);
	free_t_pipe(test_pipe);
	free(test_pipe);
	free(first);
	free(next);
	free_them(&cmd, &first_redir, &next_redir);
}