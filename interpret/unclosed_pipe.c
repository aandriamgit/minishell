/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:31:20 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/23 18:30:30 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpret.h"

static void	extra_pipe(int *i, int *res, char *str, t_vars *vars)
{
	int	j;

	j = *i;
	j++;
	*i = *i + 1;
	if (!str[j])
	{
		ft_perror_soft("syntax error", "unclosed '|'\n", vars, 2);
		*res = 1;
		return ;
	}
	while (str[j] == ' ' || str[j] == '\t')
	{
		*i = *i + 1;
		j++;
		if (!str[*i])
		{
			ft_perror_soft("syntax error", "unclosed '|'\n", vars, 2);
			*res = 1;
			return ;
		}
	}
}

static void	extra_backslach(int *i, int *res, char *str, t_vars *vars)
{
	int	j;

	j = *i;
	j++;
	*i = *i + 1;
	if (!str[j])
	{
		ft_perror_soft("syntax error", "unclosed '|'\n", vars, 2);
		*res = 1;
		return ;
	}
	while (str[j] == ' ' || str[j] == '\t')
	{
		*i = *i + 1;
		j++;
		if (!str[*i])
		{
			ft_perror_soft("syntax error", "unclosed '|'\n", vars, 2);
			*res = 1;
			return ;
		}
	}
}

static void	extra_semicolone(int *i, int *res, char *str, t_vars *vars)
{
	int	j;

	j = *i;
	j++;
	*i = *i + 1;
	if (!str[j])
	{
		ft_perror_soft("syntax error", "unclosed '|'\n", vars, 2);
		*res = 1;
		return ;
	}
	while (str[j] == ' ' || str[j] == '\t')
	{
		*i = *i + 1;
		j++;
		if (!str[*i])
		{
			ft_perror_soft("syntax error", "unclosed '|'\n", vars, 2);
			*res = 1;
			return ;
		}
	}
}

int	unclosed_pipe(char **input, t_vars *vars)
{
	int		i;
	int		res;
	char	*str;

	i = 0;
	res = 0;
	str = *input;
	while (str[i])
	{
		if (str[i] == '|')
			extra_pipe(&i, &res, str, vars);
		else if (str[i] == '\\')
			extra_backslach(&i, &res, str, vars);
		else if (str[i] == ';')
			extra_semicolone(&i, &res, str, vars);
		if (res)
			return (res);
		if (str[i])
			i++;
	}
	return (res);
}
