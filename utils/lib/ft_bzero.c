/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:21:18 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/28 10:46:40 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;

	c = (unsigned char *)s;
	while (n > 0)
	{
		*c = 0;
		c++;
		n--;
	}
}
