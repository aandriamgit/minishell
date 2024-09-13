/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:05 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/13 14:16:04 by aandriam         ###   ########.fr       */
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
		ft_putstr_fd(input, fd);
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
			ft_add_history(input);
			if (ft_strncmp(input, "exit/n") == 0)
				exit(1);
		}
	}
	else
		printf("[Error] minishell doesn't need arguments\n");
	return (0);
}
