/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:34:59 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/26 14:05:22 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"
#include "expend/dep/dep.h"

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			skip(str, &i);
		else if (str[i] == '$')
			return (1);
		else
			i++;
	}
	return (0);
}

void	check_expand(char **str, t_list *cp_env, t_vars	*vars)
{
	int		i;
	int		j;
	char	**other;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (check(str[i]) == 1)
		{
			other = split_expand(str[i]);
			while (other[j])
			{
				if (check(other[j]) == 1 && other[j][0] != '\'')
				{
					if (other[j][0] == '$')
						simple_expend(&other[j], cp_env);
					else
						expend(&other[j], cp_env, vars);
				}
				j++;
			}
			free(str[i]);
			str[i] = ft_strjoin_space(&other);
		}
		i++;
	}
}
