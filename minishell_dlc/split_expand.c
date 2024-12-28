/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:01:36 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/28 12:31:12 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"

static int check(int i, char *str)
{
	i--;
	while (i <= 0)
	{
		if (str[i] == '$')
			return (1);
		else if (str[i] == '\'' || str[i] == '\"')
			return (0);
		i--;
	}
	return (0);
}


void	mini_count_z(char *str, int *i, int *count)
{
	if (str[(*i)] == '$')
	{
		(*count)++;
		(*i)++;
		while (str[(*i)] && (str[(*i)] != '\'' && str[(*i)] != '\"' && str[(*i)] != '$'))
			(*i)++;
	}
	else
	{
		while (str[(*i)] && (str[(*i)] != '\'' && str[(*i)] != '\"' && str[(*i)] != '$'))
			(*i)++;
		if (str[(*i)] == '$' && check((*i), str) == 1)
		{
			(*count)++;
			while (str[(*i)] && (str[(*i)] != '\'' && str[(*i)] != '\"' && str[(*i)] != '$'))
				(*i)++;
		}
	}
}

int ft_count_z(char *str)
{
	int i;
	int count;
	char c;

	count = 0;
	i = 0;
	c = '\0';
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			count++;
			c = str[i];
			i++;
			while (str[i] != c)
				i++;
			i++;
		}
		else
			mini_count_z(str, &i, &count);
	}
	return (count);
}

void init_exp(int *i, int *j, int *start)
{
	*i = 0;
	*j = 0;
	*start = 0;
}

char **split_expand(char *str)
{
	char **new;
	int var[3];
	char c;

	c = '\0';
	init_exp(&var[0], &var[1], &var[2]);
	new = malloc(sizeof(char *) * (ft_count_z(str) + 1));
	if (!new)
		return (NULL);
	while (str[var[0]])
	{
		if (str[var[0]] == '\'' || str[var[0]] == '\"')
		{
			c = str[var[0]];
			var[0]++;
			while (str[var[0]] && str[var[0]] != c)
				var[0]++;
			new[var[1]] = ft_substr_p(var[2], var[0], str);
			var[1]++;
			var[0]++;
			var[2] = var[0];
		}
		else
		{
			if (str[var[0]] == '$')
			{
				var[0]++;
				while (str[var[0]] && (str[var[0]] != '\'' && str[var[0]] != '\"' && str[var[0]] != '$'))
					var[0]++;
				new[var[1]] = ft_substr_p(var[2], var[0] - 1, str);
				var[1]++;
				var[2] = var[0];
			}
			else
			{
				while (str[var[0]] && (str[var[0]] != '\'' && str[var[0]] != '\"' && str[var[0]] != '$'))
					var[0]++;
				if (str[var[0]] == '$')
				{
					var[0]++;
					while (str[var[0]] && (str[var[0]] != '\'' && str[var[0]] != '\"' && str[var[0]] != '$'))
						var[0]++;
					new[var[1]] = ft_substr_p(var[2], var[0] - 1, str);
					var[1]++;
					var[2] = var[0];
				}
				else
				{
					new[var[1]] = ft_substr_p(var[2], var[0] - 1, str);
					var[1]++;
					var[2] = var[0];
				}
			}
		}
	}
	new[var[1]] = NULL;
	return (new);
}


