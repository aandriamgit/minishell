/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:09:38 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 13:24:09 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_putnbr_fd_a(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd_a("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd_a('-', fd);
		ft_putnbr_fd_a(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd_a(n / 10, fd);
		ft_putchar_fd_a(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd_a(n + '0', fd);
}
