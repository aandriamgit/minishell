/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:25:48 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/22 18:48:39 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../redirection_test.h"

void	simple_test_heredoc(char *cmd, char *lol, t_vars *vars)
{
	char			**splited;
	char			**big_param;
	t_pipe			*test_pipe;
	t_redirection	*redir;

	splited = ft_split(lol, ' ');
	free(lol);
	big_param = ft_split(cmd, ' ');
	free(cmd);
	test_pipe = malloc(sizeof(t_pipe));
	redir = gen_redir(splited[0], splited[1], NULL);
	test_pipe->cmd = gen_cmd(big_param[0], big_param, redir, NULL);
	test_pipe->next = NULL;
	test_pipe->prev = NULL;
	if (!have_heredoc(test_pipe))
		exec_t_pipe(test_pipe);
	else
		heredoc_supremacy(test_pipe, vars);
	free_t_pipe(test_pipe);
	free(splited);
	free(test_pipe);
}

void	heredoc_redir_test(char *str, t_vars *vars)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\nheredoc test whit 'cat << lol'\n", 1);
	simple_test_heredoc(ft_strdup("cat"), ft_strdup("<< lol"), vars);
}
