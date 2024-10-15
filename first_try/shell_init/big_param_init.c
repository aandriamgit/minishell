/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_param_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:00:28 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/25 18:00:45 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	big_param_init(char ***big_param, t_vars vars)
{
	*big_param = malloc(sizeof(char *) * 3);
	if (*big_param == NULL)
		exit(0);
	(*big_param)[0] = ft_strdup("mkdir");
	(*big_param)[1] = ft_strdup(vars.log_dir);
	(*big_param)[2] = NULL;
}
