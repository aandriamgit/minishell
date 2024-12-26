/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:42:13 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/23 15:22:30 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"
#include <stdio.h>

void	ft_trim(int start, int end, char **str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen_p(*str) - (end - start + 1) + 1));
	if (!new)
		return ;
	while ((*str)[i])
	{
		if (i >= start && i <= end)
			i++;
		else
		{
			new[j] = (*str)[i];
			j++;
			i++;
		}
	}
	new[j] = '\0';
	free(*str);
	*str = ft_strdup_p(new);
	free(new);
}

void	make_type(int *i, char *str, char **type)
{
	if (str[*i] == str[*i + 1])
	{
		*type = ft_substr_p(*i, *i + 1, str);
		*i = *i + 2;
	}
	else
	{
		*type = ft_substr_p(*i, *i, str);
		(*i)++;
	}
	while (str[*i] == ' ')
		(*i)++;
}

void	remove_replace(char **str, int i, t_redir **redir)
{
	int		start;
	char	*type;
	char	*file;
	int		c;
	char	*tmp;

	type = NULL;
	file = NULL;
	tmp = ft_strdup_p(*str);
	c = i;
	start = 0;
	make_type(&i, *str, &type);
	start = i;
	while ((*str)[i] && (*str)[i] != ' ')
	{
		if ((*str)[i] == '\'' || (*str)[i] == '\"')
			skip_x(&i, *str, (*str)[i]);
		else
			i++;
	}
	file = ft_substr_p(start, i - 1, *str);
	ft_trim(c, i - 1, &tmp);
	creat_chain_of_redir(redir, creat_bloc_redir(type, file));
	free(*str);
	*str = ft_strdup_p(tmp);
	free(tmp);
	free(file);
}

t_redir	*redirection(char **str)
{
	int		i;
	t_redir	*redir;
	char	c;

	c = '\0';
	i = 0;
	redir = NULL;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' || (*str)[i] == '\"')
			skip_x(&i, *str, (*str)[i]);
		else if ((*str)[i] && ((*str)[i] == '>' || (*str)[i] == '<'))
		{
			remove_replace(str, i, &redir);
			i = 0;
		}
		else
			i++;
	}
	return (redir);
}
