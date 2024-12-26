/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:12:12 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:27:07 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../interpret/interpret.h"
#include "../../../minishell.h"
#include "../../utils.h"
#include <dirent.h>

static int	extra(t_vars *vars, char *char_nbr)
{
	int		res;
	char	*tmp;
	char	*john;

	john = ft_strjoin_a("/", char_nbr);
	tmp = ft_strjoin_a(vars->stderr_a, john);
	free(john);
	res = open(tmp, O_WRONLY | O_APPEND | O_CREAT, 0755);
	free(tmp);
	return (res);
}

int	gen_fd(t_vars *vars)
{
	int		res;
	char	*char_nbr;

	char_nbr = ft_itoa_a(vars->err_nbr);
	res = extra(vars, char_nbr);
	free(char_nbr);
	return (res);
}
