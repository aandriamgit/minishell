/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:55:04 by mravelon          #+#    #+#             */
/*   Updated: 2024/10/09 15:05:59 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}