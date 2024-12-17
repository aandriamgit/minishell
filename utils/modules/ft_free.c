/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:28:12 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/13 09:42:03 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	ft_free_tab(char ***argv)
{
	int	i;

	i = 0;
	while ((*argv)[i] != NULL)
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
	*argv = NULL;
}

void	ft_free_t_list(t_list **env)
{
	t_list	*voyager_one;
	t_list	*tmp;

	voyager_one = *env;
	while (voyager_one)
	{
		tmp = voyager_one;
		voyager_one = voyager_one->next;
		if (tmp->parameter)
			free(tmp->parameter);
		if (tmp->arg)
			free(tmp->arg);
		free(tmp);
	}
}

static void	free_redir(t_redirection_a *redir)
{
	t_redirection_a	*tmp;

	while (redir)
	{
		tmp = redir;
		free(redir->type);
		free(redir->file);
		redir = redir->next;
		free(tmp);
	}
}

void	ft_free_t_pipe_a(t_pipe_a *pipe_a)
{
	while (pipe_a)
	{
		free_redir(pipe_a->cmd->redir);
		ft_free_tab(&pipe_a->cmd->args);
		free(pipe_a->cmd);
		pipe_a = pipe_a->next;
	}
}

void	ft_free_t_pipe_again(t_pipe_a **p_test)
{
	t_pipe_a	*tmp;
	t_pipe_a	*tmp_again;

	tmp = *p_test;
	while (tmp)
	{
		tmp_again = tmp;
		tmp = tmp->next;
		free(tmp_again);
	}
}
