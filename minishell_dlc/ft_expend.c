/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:08:58 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/28 16:10:30 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"

int	size_char(char *str)
{
	int		i;
	int		count;
	char	*xp;

	i = 0;
	count = 0;
	xp = ft_strdup_p("");
	while (str[i])
	{
		if (str[i] == '$')
			for_dollars(&i, &count, str, &xp);
		else if (str[i] == '\'' || str[i] == '\"')
			for_quote(&i, &count, str, &xp);
		else
			for_simple(&i, &count, str, &xp);
	}
	free(xp);
	return (count);
}

void	init_expend(int *i, int *j, int *count, int *start)
{
	*j = 0;
	*i = 0;
	*start = 0;
	*count = -1;
}

char	**ft_expend(char *str)
{
	char	**split;
	int		i;
	int		start;
	int		count;
	int		j;

	init_expend(&i, &j, &count, &start);
	split = malloc(sizeof(char *) * (size_char(str) + 1));
	if (!split)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$')
			for_dollars(&i, &count, str, &split[j]);
		else if (str[i] == '\'' || str[i] == '\"')
			for_quote(&i, &count, str, &split[j]);
		else if (str[i])
			for_simple(&i, &count, str, &split[j]);
		j++;
	}
	split[j] = NULL;
	return (split);
}
