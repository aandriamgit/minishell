/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:36:57 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/23 13:59:34 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ex_quote(char **str, t_list *env_cp)
{
	int start;
	int i;
	int j;
	char *tmp;
	char c;

	i = 0;
	j = 0;
	tmp = NULL;
	start = 0;
	c = (*str)[i];
	i++;
	start = i;
	while ((*str)[i] && (*str)[i] != c)
		i++;
	tmp = ft_substr_p(start, i - 1, *str);
	free(*str);
	formating(&tmp, env_cp);
	*str = malloc(sizeof(char) * (ft_strlen_p(tmp) + 3));
	if (!(*str))
		return ;
	i = 0;
	(*str)[j] = c;
		j++;
	while (tmp[i])
	{
		(*str)[j] = tmp[i];
		i++;
		j++;
	}
	(*str)[j] = c;
	j++;
	(*str)[j] = '\0';
	free(tmp);
}

















