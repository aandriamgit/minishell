/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_o_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:41:37 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/12 16:43:00 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../simple_execution.h"

t_pipe	*generate_redir(char *cmd, char *type, char *dir)
{
	t_pipe	*m_res;

	m_res = malloc(sizeof(t_pipe));
	m_res->redirection = redir_gen_o(cmd, type, dir);
	m_res->next = NULL;
	return (m_res);
}

void	test_exec_redir(t_pipe *lol, t_vars *vars)
{
	if (ft_strncmp(lol->redirection->type, "<") == 0)
		input_redir_test(lol, vars->log_dir);
	else if (ft_strncmp(lol->redirection->type, "<<") == 0)
		here_doc_test(lol);
	else if (ft_strncmp(lol->redirection->type, ">") == 0)
		output_redir_test(lol);
	else if (ft_strncmp(lol->redirection->type, ">>") == 0)
		append_redir_test(lol);
	else
		ft_putstr_fd("not a redirection\n", 1);
}
