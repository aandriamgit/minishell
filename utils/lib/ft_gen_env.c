/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:11:40 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/18 08:38:01 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "lib.h"

static int	gen_count(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

char	**ft_gen_env(t_list *list)
{
	char	**res;
	int		count;
	int		i;

	i = 0;
	count = gen_count(list);
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	res[count] = NULL;
	while (i < count)
	{
		res[i] = ft_strdup_a(list->cmd);
		list = list->next;
		i++;
	}
	return (res);
}
