/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:15 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/02 15:11:09 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr_p(int start, int end, char *str)
{
	char *new;
	int i;

	i = 0;
	new = malloc (sizeof(char) * (end - start + 2));
	if (!new)
		return (NULL);
	while (start <= end)
	{
		new[i] = str[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
