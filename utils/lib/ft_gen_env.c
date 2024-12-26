/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:11:40 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/26 12:22:16 by aandriam         ###   ########.fr       */
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

static char	*get_new_shlvl(t_list *list)
{
	char	*res;
	char	*tmp_again;
	char	*tmp;
	int		int_tmp;

	tmp = ft_getenv("SHLVL", list);
	int_tmp = ft_atoi_a(tmp);
	int_tmp++;
	tmp_again = ft_itoa_a(int_tmp);
	res = ft_strjoin_a("SHLVL=", tmp_again);
	free(tmp);
	free(tmp_again);
	return (res);
}

char	**ft_gen_env(t_list *list)
{
	char	**res;
	char	*new;
	int		count;
	int		i;

	i = 0;
	new = get_new_shlvl(list);
	export_with_arg(&list, new);
	free(new);
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
