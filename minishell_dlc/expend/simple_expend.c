/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_expend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:54:34 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/18 17:29:34 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include "dep/dep.h"

/*int cmp(char *f, char *s)
{
	int i;

	i = 0;
	while (f[i] && s[i])
	{
		if ((f[i] - s[i]) != 0)
			return (f[i] - s[i]);
		i++;
	}
	if (f[i] != '\0' && s[i] == '\0')
		return (f[i]);
	else if (f[i] == '\0' && s[i] != '\0')
			return (s[i]);
	else
		return (0);
}*/



static int	found_it(char *tmp, char *parameter)
{
	int	i;

	i = 0;
	printf("tmp = %s     parameter = %s\n", tmp, parameter);
	while (parameter[i])
	{
		if (parameter[i] == '=')
		{
			if (ft_strncmp_ap(tmp, parameter, i) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

static void	replace_it(char **to_replace, char *parameter)
{
	int		i;
	char	*new;

	i = 0;
	while (parameter[i])
	{
		if (parameter[i] == '=')
		{
			new = ft_substr_ap(parameter, i + 1, ft_strlen_ap(parameter));
			if (!new)
				return ;
			free(*to_replace);
			*to_replace = new;
		}
		i++;
	}
}

void	simple_expend(char **str, t_list *env)
{
	char	*to_replace;
	char	*tmp;
	t_list	*voyager_one;

	printf("str = %s\n", *str);
	tmp = *str;
	if (tmp[0] == '$')
		tmp++;
	if (tmp && tmp[1] && tmp[1] != '"')
	{
		to_replace = ft_strdup_ap("");
		voyager_one = env;
		while (voyager_one)
		{
			printf("here\n");
			if (found_it(tmp, voyager_one->cmd) == 1)
			{
				printf("here\n");
				replace_it(&to_replace, voyager_one->cmd);
				break ;
			}
			voyager_one = voyager_one->next;
		}
		free(*str);
		*str = to_replace;
	}
}
