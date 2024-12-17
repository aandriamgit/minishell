/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:25:42 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/13 11:27:19 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strdup_a(const char *s)
{
	int		i;
	int		len_s;
	char	*strcopy;

	i = 0;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen_a(s);
	strcopy = malloc(sizeof(char) * (len_s + 1));
	if (strcopy == 0)
		return (NULL);
	while (s[i] != 0)
	{
		strcopy[i] = s[i];
		i++;
	}
	strcopy[i] = '\0';
	return (strcopy);
}
