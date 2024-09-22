/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:21:23 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/22 17:26:36 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*typedef struct s_tree
{
	char *cmd;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;*/

void binary_tree(char *new_input)
{
	char **piped_input;
	t_tree *tree;
	int i;

	i = 0;
	piped_input = ft_split(new_input, '|');

	while (piped_input[i])
	{
		right_chain_of_leaf(&tree, creat_leaf(piped_input[i]));
		i++;
	}
}
