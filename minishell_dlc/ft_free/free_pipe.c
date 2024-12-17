/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:59:32 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/16 18:07:08 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void free_arg(char ***str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*str)
	{
		while ((*str)[i])
		{
			free((*str)[i]);
			i++;
		}
		free(*str);
	}
}

void	free_cmd(t_cmd **x)
{
	t_cmd *y;

	y = *x;
	if (y)
	{
		if (y->arg)
			free_arg(&(y->arg));
		if (y->cmd)
			free(y->cmd);
	}
}

void	free_redir(t_redir **x)
{
	t_redir *y;

	y = *x;
	if (x)
	{
		while (y)
		{
			if (y->file)
				free(y->file);
			if (y->type)
				free(y->file);
			y = y->next;	
		}
		free(y);
	}
}

void	free_pipe(t_pipe **x)
{
	t_pipe *y;

	y = *x;
	if (y)
	{
		while (y)
		{
			free_redir(&(y->redir));
			free_cmd(&(y->cmd));
			free(y);
			y = y->next;
		}
	}
}

