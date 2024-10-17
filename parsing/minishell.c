/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:29:47 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/25 13:42:36 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *input;
	char *new_input;
	t_pipe *cmd;

	(void)argv;
	if (argc == 1)
	{
		while (1)
		{
			input = readline("minishell >");
			if (ft_strncmp(input, "exit") == 0)
				exit(1);
			add_history(input);
			new_input = formating(input);
			printf("new_input = %s\n", new_input);
			cmd = binary_tree(new_input);
		}
	}
	return (0);
}
