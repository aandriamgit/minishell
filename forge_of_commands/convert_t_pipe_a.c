/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_t_pipe_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:47:49 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:26:01 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forge_of_commands.h"

static void	extras(t_pipe_a **res, t_pipe_a **to_add, t_pipe *cmd)
{
	t_redir			*v;
	t_redirection_a	*redir;
	t_redirection_a	*to_add_redir;
	t_command_a		*cmd_a;

	v = cmd->redir;
	redir = NULL;
	while (v)
	{
		to_add_redir = gen_redir(ft_strdup_a(v->type), ft_strdup_a(v->file),
				NULL);
		add_redir_end(&redir, &to_add_redir);
		v = v->next;
	}
	cmd_a = gen_cmd(cmd->cmd->cmd, cmd->cmd->arg, redir, NULL);
	*to_add = gen_pipe_a(cmd_a, NULL, NULL);
	add_pipe_end(res, to_add);
}

t_pipe_a	*convert_t_pipe_a(t_pipe *cmd)
{
	t_pipe_a	*res;
	t_pipe_a	*to_add;

	res = NULL;
	while (cmd)
	{
		extras(&res, &to_add, cmd);
		cmd = cmd->next;
	}
	return (res);
}
