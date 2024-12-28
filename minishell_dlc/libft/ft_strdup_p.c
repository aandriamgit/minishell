/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:38:38 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 10:53:13 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_p(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen_p(str) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
