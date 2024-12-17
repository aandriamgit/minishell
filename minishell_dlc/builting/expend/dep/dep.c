/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:57:59 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/26 13:52:28 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dep.h"

size_t	ft_strlen_a(const char *s)
{
	size_t	numb_bytes;

	numb_bytes = 0;
	while (s[numb_bytes] != '\0')
	{
		numb_bytes++;
	}
	return (numb_bytes);
}

char	*ft_strdup_a(const char *s)
{
	int		i;
	size_t	len_s;
	char	*strcopy;

	i = 0;
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

int	ft_strncmp_a(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - s2[i]);
}

char	*ft_substr_a(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (start > ft_strlen_a(s) || start < 0)
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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
