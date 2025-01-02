/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:58:09 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/02 12:58:36 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*pointer;
	size_t	i;

	i = 0;
	pointer = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			pointer = (char *)&s[i];
			return (pointer);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		pointer = (char *)&s[i];
	}
	return (pointer);
}
