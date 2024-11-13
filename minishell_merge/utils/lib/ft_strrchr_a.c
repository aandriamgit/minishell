/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:45:26 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/12 06:48:26 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strrchr_a(const char *s, int c)
{
	char	*point;
	size_t	i;

	i = 0;
	point = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			point = (char *)&s[i];
		}
		i++;
	}
	if ((char)c == '\0')
	{
		point = (char *)&s[i];
	}
	return (point);
}
