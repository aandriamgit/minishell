/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:36:57 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/10 14:52:27 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ex_quote(char **str, t_list *env_cp)
{
	char *new;
	char c;
	int i;
	int j;

	i = 0;
	j = 0;
	c = (*str)[i];
	i++;
	new = malloc(sizeof(char) * (ft_strlen_p(*str) - 1));
	if (!new)
		return ;
	while ((*str)[i] != c)
	{
		new[j] = (*str)[i];
		j++;
		i++;
	}
	new[j] = '\0';
	i = 0;
	j = 0;
	formating(&new, env_cp);
	free(*str);
	*str = malloc (sizeof(char) * (ft_strlen_p(new) + 2));
	if (!(*str))
		return ;
	(*str)[j] = c;
	j++;
	while (new[i])
	{
		(*str)[j] = new[i];
		i++;
		j++;
	}
	(*str)[j] = c;
	j++;
	(*str)[j] = '\0';
}
