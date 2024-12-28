/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:03:37 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/28 11:36:15 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"

void	skip(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)++;
	while (str[*i] != c)
		(*i)++;
	(*i)++;
}

int	space(int i, char *str)
{
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
			skip(str, &i);
		else if (str[i] && str[i] == ' ')
		{
			if (i != 0 && space(i, str) == 1 && str[i - 1] != ' ')
				count++;
			while (str[i] == ' ')
				i++;
		}
		else if (str[i])
			i++;
	}
	if (i != 0)
		count++;
	return (count);
}

void	init_split(int *i, int *j, char ***new, char *str)
{
	*j = 0;
	*new = malloc(sizeof(char *) * (count(str) + 1));
	if (!(*new))
		return ;
	*i = 0;
	while (str[*i] == ' ')
		(*i)++;
}

char	**ft_split_na(char *str)
{
	int		var[3];
	char	**new;

	init_split(&var[0], &var[1], &new, str);
	var[2] = var[0];
	while (str[var[0]])
	{
		if (str[var[0]] == '\"' || str[var[0]] == '\'')
			skip(str, &var[0]);
		else if (str[var[0]] == ' ')
		{
			new[var[1]++] = ft_substr_p(var[2], var[0] - 1, str);
			while (str[var[0]] == ' ')
				var[0]++;
			if (str[var[0]])
				var[2] = var[0];
		}
		else if (str[var[0]])
			var[0]++;
	}
	if (var[0] != 0)
		new[var[1]++] = ft_substr_p(var[2], var[0] - 1, str);
	new[var[1]] = NULL;
	return (new);
}
