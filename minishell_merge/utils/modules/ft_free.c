/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:28:12 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/13 10:00:06 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	ft_free_tab(char ***argv)
{
	int	i;

	i = 0;
	while ((*argv)[i] != NULL)
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
}

void	ft_free_t_list(t_list **env)
{
	t_list	*voyager_one;
	t_list	*tmp;

	voyager_one = *env;
	while (voyager_one)
	{
		tmp = voyager_one;
		voyager_one = voyager_one->next;
		free(tmp);
	}
}
