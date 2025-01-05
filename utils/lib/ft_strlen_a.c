/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:11:12 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/05 08:54:06 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

size_t	ft_strlen_exit_a(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && ft_isdigit_a(s[i]))
		i++;
	return (i);
}

size_t	ft_strlen_a(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
