/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:05 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/05 11:48:28 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr(char *lol)
{
	int	i;

	i = 0;
	while (lol[i])
	{
		write(1, &lol[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	flag;

	(void)argv;
	flag = 0;
	if (argc == 1)
	{
		while (1)
		{
			if (flag == 0)
			{
				ft_putstr("Minishell>   ");
				flag = 1;
			}
		}
	}
	else
		printf("[Error] minishell doesn't need arguments\n");
	return (0);
}
