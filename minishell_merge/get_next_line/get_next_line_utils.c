/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:12:11 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/15 18:03:56 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_them(char *new_buff, char *temp)
{
	char	*newbie;
	int		i;
	int		j;
	int		len;

	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(new_buff) + ft_strlen(temp);
	newbie = malloc(sizeof(char) * (len + 1));
	if (newbie == 0)
		return (NULL);
	while (new_buff[i] != '\0')
	{
		newbie[i] = new_buff[i];
		i++;
	}
	free(new_buff);
	while (temp[j] != '\0')
	{
		newbie[i + j] = temp[j];
		j++;
	}
	return (newbie[i + j] = '\0', newbie);
}

char	have_nl(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return ('n');
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return ('y');
		i++;
	}
	return ('n');
}
