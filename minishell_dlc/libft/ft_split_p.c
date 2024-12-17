/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:08:21 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/28 13:53:41 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_conteur(char const *s, char c)
{
	size_t	i;
	size_t	conteur;

	conteur = 0;
	i = 0;
	if (!s)
		return (1);
	while (s[i] != '\0')
	{
		if (ft_strlen_p((char *)s) == 1 && s[i] != c && s[i + 1] == '\0')
			return (conteur + 1);
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			conteur++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (conteur);
}

static void	ft_initiate(size_t *i, size_t *start, size_t *end, size_t *u)
{
	*i = 0;
	*start = 0;
	*end = 0;
	*u = 0;
}

char	**ft_item(char **res, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	u;

	ft_initiate(&i, &start, &end, &u);
	if (ft_conteur(s, c) != 0)
	{
		while (u < ft_conteur(s, c))
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == c || s[i] == '\0')
				end = i - start;
			res[u] = (ft_substr_p(start, end, (char *)s));
			u++;
		}
	}
	res[u] = NULL;
	return (res);
}

char	**ft_split_p(char const *s, char c)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (ft_conteur(s, c) + 1));
	if (!res)
		return (NULL);
	res = (char **)ft_item(res, s, c);
	return (res);
}
