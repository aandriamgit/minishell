/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:05 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/09 14:21:19 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_readline(char *prompt)
{
	char	*buffer;

	ft_putstr_fd(prompt, 1);
	buffer = malloc(1025);
	buffer[1024] = '\0';
	read(0, buffer, 1024);
	return (buffer);
}

void	ft_add_history(char *input)
{
	int	fd;
	int	nb;

	if (input[0] != '\n')
	{
		fd = open("ft_add_history/.minishell_history", O_RDWR | O_APPEND);
		if (fd == -1)
			exit(1);
		nb = number_of_line(fd);
		ft_putstr_fd("==", fd);
		ft_putnbr_fd(nb, fd);
		ft_putstr_fd("== ", fd);
		free(input);
	}
}

int	main(int argc, char **argv)
{
	char	*input;

	(void)argv;
	if (argc == 1)
	{
		while (1)
		{
			input = ft_readline("minishell > ");
			if (ft_strncmp(input, "exit") == 0)
				exit(1);
			ft_add_history(input);
		}
	}
	else
		printf("[Error] minishell doesn't need arguments\n");
	return (0);
}
