/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_leaf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:00:07 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/22 18:34:56 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void left_chain_of_leaf(t_tree **chained_leaf, t_tree *leaf)
{
	t_tree *tmp;

	if (*chained_leaf == NULL)
		*chained_leaf = leaf;
	else
	{
		tmp = *chained_leaf;
		while (tmp->left)
			tmp = tmp->left;
		tmp->left = leaf;
	}
}

void rigth_chain_of_leaf(t_tree **chained_leaf, t_tree *leaf)
{
	static char *redirection[4] = {">", "<", ">>", "<<"};
	t_tree *tmp;

	if (*chained_leaf == NULL)
		*chained_leaf = leaf;
	else
	{
		tmp = *chained_leaf;
		while (tmp->right)
			tmp = tmp->right;
		tmp->right = leaf;
	}
}

t_tree *creat_leaf(char *cmd)
{
	t_tree *leaf;

	leaf = malloc(sizeof(t_tree));
	if (!leaf)
		return (NULL);
	leaf->cmd = cmd;
	leaf->left = NULL;
	leaf->right = NULL;
	return (leaf);
}
