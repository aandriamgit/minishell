/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:52:48 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:21:00 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	count_that_thing(int n)
{
	int	result_count;

	result_count = 0;
	if (n < 0)
		result_count += 1;
	else if (n == 0)
		result_count = 1;
	while (n != 0)
	{
		n /= 10;
		result_count++;
	}
	return (result_count);
}

char	*ft_itoa_a(int n)
{
	char	*result;
	long	number;
	int		length;

	length = count_that_thing(n);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		number = -(long)n;
	}
	else
		number = n;
	if (n == 0)
		result[0] = '0';
	while (number != 0)
	{
		result[length - 1] = number % 10 + '0';
		number = number / 10;
		length--;
	}
	return (result);
}
