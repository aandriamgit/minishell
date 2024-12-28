/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:43:54 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 10:54:54 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_p(char *first, char *second)
{
	int	i;

	i = 0;
	if (!first[i])
		return (-second[i]);
	while (first[i])
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	if (!first[i])
		return (second[i]);
	return (0);
}
