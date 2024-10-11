/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:57:45 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/11 11:06:31 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_command	*cmd_gen(char *input)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	cmd->args = ft_split(input, ' ');
	cmd->cmd = cmd->args[0];
	return (cmd);
}

t_redirection	*redir_gen(char *input)
{
	t_redirection	*t_redir;

	t_redir = malloc(sizeof(t_redirection));
	t_redir->type = NULL;
	t_redir->next = NULL;
	t_redir->cmd = cmd_gen(input);
	return (t_redir);
}

t_pipe	*other_pipe(void)
{
	t_pipe	*m_pipe;

	m_pipe = malloc(sizeof(t_pipe));
	m_pipe->redirection = redir_gen("wc -l");
	m_pipe->next = NULL;
	return (m_pipe);
}

t_pipe	*parsing_test(void)
{
	t_pipe	*m_pipe;

	m_pipe = malloc(sizeof(t_pipe));
	m_pipe->redirection = redir_gen("ls -a");
	m_pipe->next = other_pipe();
	return (m_pipe);
}
