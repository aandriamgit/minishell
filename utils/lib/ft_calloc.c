/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:36:19 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/28 10:45:49 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*point;
	size_t	count;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	count = nmemb * size;
	point = malloc(count);
	if (point == 0)
		return (NULL);
	ft_bzero(point, count);
	return (point);
}
