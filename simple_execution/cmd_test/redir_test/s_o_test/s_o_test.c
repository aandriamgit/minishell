/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_o_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:41:37 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/11 16:36:04 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../simple_execution.h"

t_redirection	*add_next_redir(char *cmd, char *type, void *next)
{
	t_redirection	*t_redir;

	t_redir = malloc(sizeof(t_redirection));
	t_redir->type = type;
	t_redir->next = next;
	t_redir->cmd->args = ft_split(cmd, ' ');
	t_redir->cmd->cmd = t_redir->cmd->args[0];
	return (t_redir);
}

t_pipe	*generate_redir(char *cmd, char *type, char *dir)
{
	t_pipe	*m_res;

	m_res = malloc(sizeof(t_pipe));
	m_res->redirection->type = ft_strdup(type);
	m_res->redirection->next = add_next_redir(dir, NULL, NULL);
	m_res->redirection->cmd->args = ft_split(cmd, ' ');
	m_res->redirection->cmd->cmd = m_res->redirection->cmd->args[0];
	m_res->next = NULL;
	return (m_res);
}
