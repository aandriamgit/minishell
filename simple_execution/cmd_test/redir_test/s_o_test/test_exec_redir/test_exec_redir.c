/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:00:42 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/14 15:26:33 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../simple_execution.h"

void	input_redir_test(t_pipe *lol, char *log_dir)
{
	char	*dir;
	char	*lol_dir;
	char	*tmp;
	char	*input;

	lol_dir = lol->redirection->next->cmd->cmd;
	tmp = ft_strjoin(log_dir, "/");
	dir = ft_strjoin(tmp, lol_dir);
	free(tmp);
	free(lol_dir);
	if (file_exist(dir))
	{
		input = take_input(dir);
		ft_putstr_fd("the content of the file is ", 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd(input, 1);
	}
	else
	{
		ft_putstr_fd("minishell: ", 1);
		ft_putstr_fd(lol_dir, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
	}
}

void	here_doc_test(t_pipe *lol)
{
	(void)lol;
}

void	output_redir_test(t_pipe *lol)
{
	(void)lol;
}

void	append_redir_test(t_pipe *lol)
{
	(void)lol;
}
