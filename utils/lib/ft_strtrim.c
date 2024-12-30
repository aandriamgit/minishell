/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:18:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/30 15:52:36 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_trim;
	size_t	i;
	size_t	j;
	size_t	len;

	j = ft_strlen_a(s1);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (j > i && ft_strchr(set, s1[j]) != NULL)
		j--;
	len = j - i;
	new_trim = ft_substr_a(s1, (unsigned int)i, (len + 1));
	return (new_trim);
}

void	ft_strtrim_special(char **s1, const char *set)
{
	char	*new;

	new = ft_strtrim(*s1, set);
	free(*s1);
	*s1 = new;
}
