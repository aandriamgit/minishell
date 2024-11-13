/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:53:44 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/13 09:41:30 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_substr(const char *str, int start, int end)
{
	char	*new;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (start > ft_strlen(str))
		end = 0;
	if (end > ft_strlen(str))
		end = ft_strlen(str);
	new = malloc((sizeof(char)) * (end + 1));
	if (new == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		if (i >= (size_t)start && j < (size_t)end)
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}
