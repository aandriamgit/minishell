/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:44:07 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/28 13:53:00 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_p(int i, int fd)
{
	char str[10] = "0123456789";

	if (i == -2147483648)
		ft_putstr_p("-2147483648", fd);
	if (i < 0)
	{
		ft_putstr_p("-", fd);
		ft_putnbr_p(-i, fd);
	}
	else if (i >= 0 && i <= 9)
		ft_putchar_p(str[i], 1);
	else
	{
		ft_putnbr_p(i / 10, fd);
		ft_putnbr_p(i % 10, fd);
	}
}
