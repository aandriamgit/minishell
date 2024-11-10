/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:10:00 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/10 17:24:56 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_substr_a(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (start > ft_strlen_a(s))
		len = 0;
	if (len > ft_strlen_a(s))
		len = ft_strlen_a(s);
	new = malloc((sizeof(char)) * (len + 1));
	if (new == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			new[j] = s[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}
