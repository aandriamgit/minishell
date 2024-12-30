/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:16:50 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/30 14:53:56 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int 	numnum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c == '?')
		return (1);
	else
		return (0);
}

void	for_dollars(int *i, int *count, char *str, char **new_x)
{
	int	start;

	start = *i;
	if ((*count) >= 0)
		(*count)++;
	(*i)++;
	while (str[*i] && (str[*i] != '\'' && str[*i] != '\"' && str[*i] != '$') && (numnum(str[*i]) == 1))
		(*i)++;
	if ((*count) < 0)
		(*new_x) = ft_substr_p(start, *i - 1, str);
}

void	for_quote(int *i, int *count, char *str, char **new_x)
{
	int	start;

	start = *i;
	if (*count >= 0)
		(*count)++;
	skip_x(i, str, str[*i]);
	if (*count < 0)
		*new_x = ft_substr_p(start, *i - 1, str);
}

void	for_simple(int *i, int *count, char *str, char **new_x)
{
	int	start;

	start = *i;
	if ((*count) >= 0)
		(*count)++;
	while (str[*i] && (str[*i] != '\'' && str[*i] != '\"' && str[*i] != '$'))
		(*i)++;
	if ((*count) < 0)
		*new_x = ft_substr_p(start, *i - 1, str);
}
