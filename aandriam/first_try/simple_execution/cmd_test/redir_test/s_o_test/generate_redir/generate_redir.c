/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:32:48 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/12 16:21:56 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../simple_execution.h"

t_command	*cmd_gen_redir(char *input)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	cmd->args = ft_split(input, ' ');
	cmd->cmd = cmd->args[0];
	return (cmd);
}

t_redirection	*end_of(char *dir)
{
	t_redirection	*t_redir;

	t_redir = malloc(sizeof(t_redirection));
	t_redir->type = NULL;
	t_redir->next = NULL;
	t_redir->cmd = cmd_gen_redir(dir);
	return (t_redir);
}

t_redirection	*redir_gen_o(char *cmd, char *type, char *dir)
{
	t_redirection	*t_redir;

	t_redir = malloc(sizeof(t_redirection));
	t_redir->cmd = cmd_gen_redir(cmd);
	t_redir->type = ft_strdup(type);
	t_redir->next = end_of(dir);
	return (t_redir);
}
