/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:53:35 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/16 17:03:21 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpret.h"
#include <unistd.h>

static int	is_closed(char *lol, char quote, int start)
{
	int	i;

	i = start;
	while (lol[i] != quote)
	{
		if (!lol[i])
			return (0);
		i++;
	}
	return (1);
}

static int	have_quote(char *new, char quote)
{
	int	i;

	i = 0;
	while (new[i])
	{
		if (new[i] == quote)
			return (1);
		i++;
	}
	return (0);
}

static void	uptade_input(char **input, t_vars *vars)
{
	int		fd;
	char	*tmp;
	char	*res;
	char	*fake_res;
	char	*final;

	fd = open(vars->quote_dir, O_RDONLY);
	tmp = get_next_line(fd);
	res = ft_strdup_a(tmp);
	while (tmp)
	{
		fake_res = ft_strdup_a(res);
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp)
		{
			free(res);
			res = ft_strjoin_a(fake_res, tmp);
		}
		free(fake_res);
	}
	final = ft_strjoin_a(res, *input);
	free(*input);
	free(res);
	*input = final;
}

static void	close_it(char **input, t_vars *vars, char quote)
{
	char	*new;
	int		fd;
	int		i;

	i = 0;
	fd = open(vars->quote_dir, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	new = readline("> ");
	ft_putstr_fd_a(new, fd);
	while (!have_quote(new, quote))
	{
		free(new);
		new = readline("> ");
		ft_putstr_fd_a(new, fd);
	}
	free(new);
	close(fd);
	uptade_input(input, vars);
}

void	unclosed_quote(char **input, t_vars *vars)
{
	int		i;
	char	*lol;
	char	quote;

	i = 0;
	lol = *input;
	while (lol[i])
	{
		if (lol[i] == 34 || lol[i] == 39)
		{
			quote = lol[i];
			i++;
			if (!is_closed(lol, quote, i))
			{
				close_it(input, vars, quote);
				lol = *input;
				i = -1;
			}
			else
				while (lol[i] != quote)
					i++;
		}
		i++;
	}
}
