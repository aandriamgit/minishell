/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:53:35 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/23 16:30:59 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../forge_of_commands/forge_of_commands.h"
#include "interpret.h"

static void	bad_ending(char **input, char quote, t_vars *vars)
{
	char	*str_quote;
	char	*tmp_quote;

	init_stderr(vars);
	tmp_quote = malloc(sizeof(char) * 5);
	if (!tmp_quote)
		exit(0);
	tmp_quote[0] = '\'';
	tmp_quote[1] = quote;
	tmp_quote[2] = '\'';
	tmp_quote[3] = '\n';
	tmp_quote[4] = '\0';
	str_quote = ft_strjoin_a("unexpected EOF due to unclosed ", tmp_quote);
	free(tmp_quote);
	ft_perror_soft("syntax error", str_quote, vars, 2);
	free(str_quote);
	free(*input);
	*input = NULL;
}

int	unclosed_quote(char **input, t_vars *vars)
{
	int		i;
	char	*str;
	char	quote;

	i = 0;
	str = *input;
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34)
		{
			quote = str[i];
			i++;
			while (str[i] != quote)
			{
				if (!str[i])
				{
					bad_ending(input, quote, vars);
					return (1);
				}
				i++;
			}
		}
		i++;
	}
	return (0);
}
