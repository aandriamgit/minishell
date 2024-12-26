/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:34:59 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/25 11:14:11 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"

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

void	check_expand(char **str, t_list *cp_env)
{
	int		i;
	int		j;
	char	**other;

	i = 0;
	j = 0;
	ft_putstr_p("here\n", 1);
	while (str[i])
	{
		if (check(str[i]) == 1)
		{
			ft_putstr_p("here\n", 1);
			other = split_expand(str[i]);
			while (other[j])
			{
				ft_putstr_p("other = ", 1);
				ft_putstr_p(other[j], 1);
				ft_putstr_p("\n", 1);
				if (check(other[j]) == 1 && other[j][0] != '\'')
				{
					if (other[j][0] == '$')
						simple_expend(&other[j], cp_env);
					else
						expend(&other[j], cp_env);
				}
				j++;
			}
			free(str[i]);
			str[i] = ft_strjoin_space(&other);
		}
		i++;
	}
}
