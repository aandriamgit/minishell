/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:45:26 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/24 15:45:40 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strrchr(const char *s, int c)
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
