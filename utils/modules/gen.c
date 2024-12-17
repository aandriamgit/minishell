/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:02:35 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 14:14:11 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

t_pipe_a	*gen_pipe_a(t_command_a *cmd, t_pipe_a *prev, t_pipe_a *next)
{
	t_pipe_a	*res;

	res = malloc(sizeof(t_pipe_a));
	if (!res)
		return (NULL);
	res->cmd = cmd;
	if (prev != NULL)
		res->prev = prev;
	else
		res->prev = NULL;
	if (next)
		res->next = next;
	else
		res->next = NULL;
	return (res);
}

t_command_a	*gen_cmd(char *cmd, char **big_param, void *redir, void *next)
{
	t_command_a	*cmd_res;

	cmd_res = malloc(sizeof(t_command_a));
	if (!cmd_res)
		return (NULL);
	cmd_res->cmd = cmd;
	cmd_res->args = big_param;
	cmd_res->next = next;
	cmd_res->redir = redir;
	return (cmd_res);
}

t_redirection_a	*gen_redir(char *type, char *file, void *next)
{
	t_redirection_a	*redir_res;

	redir_res = malloc(sizeof(t_redirection_a));
	if (!redir_res)
		return (NULL);
	redir_res->next = next;
	redir_res->file = file;
	redir_res->type = type;
	return (redir_res);
}
