/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:53:35 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 09:21:10 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/utils.h"
#include "../interpret.h"

void	unclosed_quote(char **input)
{
	char	*cpy;
	int		i;

	cpy = *input;
	i = 0;
	while (cpy[i])
	{
		if (cpy[i] == 34 || cpy[i] == 39)
		{
			ft_putstr_fd_a("work still on progress\n", STDOUT_FILENO);
		}
		i++;
	}
}
