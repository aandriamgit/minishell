/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:05 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/20 16:22:36 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(void)
{
	char	*home_dir;

	home_dir = getenv("HOME");
}

void	interpret(char **input)
{
	*input = ft_readline("minishell > ");
	ft_add_history(*input);
	if (ft_strncmp(*input, "exit\n") == 0)
	{
		free(*input);
		exit(1);
	}
}

void	path_execution(char *input)
{
	(void)input;
	ft_putstr_fd("path_execution\n", 1);
}

void	simple_execution(char *input)
{
	(void)input;
	ft_putstr_fd("simple_execution\n", 1);
}

int	main(int argc, char **argv)
{
	char	*input;

	(void)argv;
	if (argc == 1)
	{
		shell_init();
		while (1)
		{
			interpret(&input);
			if (input[0] == '.' || input[0] == '/')
				path_execution(input);
			else
				simple_execution(input);
			free(input);
		}
	}
	else
		printf("[Error] minishell doesn't need arguments\n");
	return (0);
}
