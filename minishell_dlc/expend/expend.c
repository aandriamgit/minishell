/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:54:34 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 14:07:25 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "dep/dep.h"

static void	add_it(char **buffer, int *i, t_vars *vars)
{
	int		j;
	char	*tmp_buffer;
	char	*char_exit_code;

	j = 0;
	char_exit_code = ft_itoa_a(vars->exit_code_int);
	tmp_buffer = *buffer;
	while (char_exit_code[j])
	{
		tmp_buffer[*i] = char_exit_code[j];
		j++;
		(*i)++;
	}
	free(char_exit_code);
}

static void	just_add_exit_code(char **str, t_vars *vars)
{
	char	*tmp_str;
	char	buffer[1024];
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp_str = *str;
	while (tmp_str[j])
	{
		if (tmp_str[j] == '$' && tmp_str[j + 1] == '?')
		{
			j = j + 2;
			add_it((char **)&buffer, &i, vars);
		}
		buffer[i] = tmp_str[j];
		if (tmp_str[j])
			j++;
		i++;
	}
	new_str = ft_strdup_a(buffer);
	free(*str);
	*str = new_str;
}

static void	expend_it(char **buffer, int *i, char **new_str)
{
	char	*tmp_buffer;
	char	*tmp_str;
	int		j;

	tmp_buffer = *buffer;
	tmp_str = *new_str;
	j = 0;
	while (tmp_str[j])
	{
		tmp_buffer[*i] = tmp_str[j];
		j++;
		(*i)++;
	}
	free(*new_str);
	*new_str = NULL;
}

static void	expend_the_else(char **str, t_vars *vars)
{
	char	buffer[1024];
	char	*new_str;
	char	*tmp_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp_str = *str;
	while (tmp_str[j])
	{
		if (tmp_str[j] == '$')
		{
			new_str = get_the_thing(tmp_str, &j, vars);
			expend_it((char **)&buffer, &i, &new_str);
		}
		buffer[i] = tmp_str[j];
		i++;
		j++;
	}
	new_str = ft_strdup_a(buffer);
	free(*str);
	*str = new_str;
}

void	expend(char **str, t_list *env, t_vars *vars)
{
	(void)env;
	just_add_exit_code(str, vars);
	expend_the_else(str, vars);
}
