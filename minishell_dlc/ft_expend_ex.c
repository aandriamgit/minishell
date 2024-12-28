/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:16:50 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/28 16:20:41 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	for_dollars(int *i, int *count, char *str, char **new_x)
{
	int	start;

	start = *i;
	if ((*count) >= 0)
		(*count)++;
	(*i)++;
	while (str[*i] && (str[*i] != '\'' && str[*i] != '\"' && str[*i] != '$'))
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
