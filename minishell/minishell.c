/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:21:31 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/05 16:13:47 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
	int flag;

	flag = 0;
	(void)argv;
	if (argc == 1)
	{
		while(1)
		{
			ft_putstr("minishell > ", 1);
			ft_readline();
		}
	}
	return (0);
}
