/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:43:54 by mravelon          #+#    #+#             */
/*   Updated: 2024/10/10 10:59:28 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_strcmp(char *first, char *second)
{
	int i;

	i = 0;

	if (!first[i])
		return (-second[i]);
	while (first[i])
	{
		if (first[i] != second[i])
		{
			return(first[i] - second[i]);
		}
		i++;
	}
	if (!first[i])
		return(second[i]);
	return (0);
}
