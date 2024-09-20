/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:05 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/20 15:00:53 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(char **input)
{
	*input = ft_readline("minishell > ");
	ft_add_history(*input);
	if (ft_strncmp(*input, "exit\n") == 0)
	{
		free(*input);
		exit(1);
	}
}

int	is_simple_command(char *input)
{
	if (input[0] == '.' || input[0] == '/')
		return (0);
	return (1);
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
		while (1)
		{
			shell_init(&input);
			if (is_simple_command(input))
				simple_execution(input);
			else
				path_execution(input);
			free(input);
		}
	}
	else
		printf("[Error] minishell doesn't need arguments\n");
	return (0);
}
