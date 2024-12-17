/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:21:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/17 18:33:36 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strjoin_free_a(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin_a(s1, s2);
	free(s1);
	return (res);
}

char	*ft_strjoin_a(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	len = 0;
	len += ft_strlen_a(s1);
	len += ft_strlen_a(s2);
	new = malloc(sizeof(*s1) * (len + 1));
	if (new == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
