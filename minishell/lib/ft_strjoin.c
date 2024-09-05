/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:05:16 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/05 15:28:02 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			res[i] = s2[j];
			i++;
			j++;
		}
		res[i] = '\0';
	}
	return (res);
}
