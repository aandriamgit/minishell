/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_bloc_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:51:48 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/18 10:27:54 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_redir	*creat_bloc_redir(char *type, char *file)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = ft_strdup_p(type);
	if (check_quotes(file) == 1)
		rm_quote(&file);
	if (file[0] == '\0')
		redir->file = NULL;
	else
		redir->file = ft_strdup_p(file);
	redir->next = NULL;
	free(type);
	return (redir);
}

void	creat_chain_of_redir(t_redir **old_list, t_redir *new_list)
{
	t_redir	*tmp;

	tmp = NULL;
	if (!(*old_list))
		*old_list = new_list;
	else
	{
		tmp = *old_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_list;
	}
}
