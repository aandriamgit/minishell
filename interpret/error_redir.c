/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:53:47 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/04 16:52:24 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpret.h"

static int	check_apend(int *i, char *str)
{
	char	x;
	int		tmp;

	x = str[*i];
	tmp = *i;
	(*i)++;
	if (str[*i] == x)
	{
		(*i)++;
		while (str[*i] && str[*i] == ' ')
			(*i)++;
		if (str[*i] == '>' || str[*i] == '<' || str[*i] == '|')
			return (1);
		if (str[*i] == '\0')
			return (1);
	}
	*i = tmp;
	return (0);
}

static int	check_redir(int *i, char *str)
{
	char	x;

	x = str[*i];
	(*i)++;
	while (str[*i] && str[*i] == ' ')
		*i = *i + 1;
	if (str[*i] == '\0' || (str[*i] == '>' && x == '<') || (str[*i] == '<'
			&& x == '>') || (str[*i] == '|'))
		return (1);
	else
		return (0);
}

int	error_redir(char *str, t_vars *t_var, int i)
{
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			skip_x(&i, str, str[i]);
		if (str[i] == '<' || str[i] == '>')
		{
			if (check_apend(&i, str) == 1)
			{
				ft_perror_soft("syntax error", "unexpected token UwU\n", t_var,
					2);
				return (1);
			}
			if (check_redir(&i, str) == 1)
			{
				ft_perror_soft("syntax error", "unexpected token OwO\n", t_var,
					2);
				return (1);
			}
		}
		else
			i++;
	}
	return (0);
}
