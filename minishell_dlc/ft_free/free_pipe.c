/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:59:32 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/17 17:29:57 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include "../../utils/utils.h"

void	free_cmd(t_cmd *x)
{
	if (x)
	{
		if (x->arg)
			ft_free_tab(&x->arg);
		if (x->cmd)
			free(x->cmd);
	}
}

void	free_redir(t_redir *x)
{
	t_redir *y;
	t_redir *z;

	y = x;
	if (x)
	{
		while (y)
		{
			z = y;
			if (y->file)
				free(y->file);
			if (y->type)
				free(y->file);
			y = y->next;	
			free(z);
		}
	}
}

void	free_pipe(t_pipe **x)
{
	t_pipe *y;
	t_pipe *z;

	y = *x;
	z = y;
	if (y)
	{
		while (y)
		{
			z = y;
			free_redir(y->redir);
			free_cmd(y->cmd);
			y = y->next;
			free(z);
		}
	}
}

