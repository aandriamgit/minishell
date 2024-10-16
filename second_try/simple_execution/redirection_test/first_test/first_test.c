/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:02 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:54 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../redirection_test.h"

t_command	*gen_cmd(char *cmd, char **big_param, void *redir, void *next)
{
	t_command	*cmd_res;

	cmd_res->cmd = ft_strdup(big_param[0]);
	cmd_res->args = big_param;
	cmd_res->next = next;
	cmd_res->redir = redir;
	return (cmd_res);
}

t_redirection	*gen_redir(char *type, char *file, void *next)
{
	t_redirection	*redir_res;

	redir_res->next = next;
	redir_res->file = file;
	redir_res->type = type;
	return (redir_res);
}

void	exec_t_pipe(t_pipe *test_pipe)
{
}
