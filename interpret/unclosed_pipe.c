/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:31:20 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/04 17:10:52 by aandriam         ###   ########.fr       */
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
	while (str[j] == ' ' || str[j] == '\t' || str[j] == '|')
	{
		*i = *i + 1;
		j++;
		if (!str[*i] || (str[*i] == '|' && str[*i + 1] == '|'))
		{
			ft_perror_soft("syntax error", "unexpected token '|'\n", vars, 2);
			*res = 1;
			return ;
		}
	}
}

static void	extra_error(int *res, t_vars *vars, char c)
{
	*res = 1;
	if (c == '\\')
		ft_perror_soft("syntax error", "unexpected token '\\'\n", vars, 2);
	else
		ft_perror_soft("syntax error", "unexpected token ';'\n", vars, 2);
}

static int	check_void_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			skip_x(&i, str, str[i]);
		else if (str[i] && i == 0 && str[i] == '|')
			return (1);
		else if (str[i] && str[i] == '|')
		{
			i++;
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i] && str[i] != '|')
			{
				while (str[i] && str[i] != '|')
				{
					if (str[i] == '\'' || str[i] == '\"')
						skip_x(&i, str, str[i]);
					i++;
				}
			}
			else
				return (1);
		}
		else
			i++;
	}
	return (0);
}

static void	extra_again(char *str, int *i, int *res, t_vars *vars)
{
	if (str[*i] == '\"' || str[*i] == '\'')
		skip_x(i, str, str[*i]);
	if (str[*i] == '|')
		extra_pipe(i, res, str, vars);
	else if (str[*i] == '\\')
		extra_error(res, vars, str[*i]);
	else if (str[*i] == ';')
		extra_error(res, vars, str[*i]);
}

int	unclosed_pipe(char **input, t_vars *vars)
{
	int		i;
	int		res;
	char	*str;

	i = 0;
	res = 0;
	str = *input;
	if (check_void_pipe(str) == 0)
	{
		while (str[i])
		{
			extra_again(str, &i, &res, vars);
			if (res)
				return (res);
			if (str[i])
				i++;
		}
	}
	else
	{
		ft_perror_soft("syntax error", "unexpected token '|'\n", vars, 2);
		return (1);
	}
	return (res);
}
