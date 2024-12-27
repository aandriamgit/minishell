/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:54:34 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 18:55:29 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "dep/dep.h"

static void	add_it(char **buffer, int *i, int *j, t_vars *vars)
{
	int		k;
	char	*tmp_buffer;
	char	*char_exit_code;

	k = 0;
	char_exit_code = ft_itoa_a(vars->exit_code_int);
	tmp_buffer = *buffer;
	while (char_exit_code[k])
	{
		tmp_buffer[*i] = char_exit_code[k];
		k++;
		(*i)++;
	}
	(*j)++;
	(*j)++;
	free(char_exit_code);
}

static void	just_add_exit_code(char **str, t_vars *vars)
{
	char	*tmp_str;
	char	*buffer;
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	tmp_str = *str;
	buffer = ft_calloc(sizeof(char), 1024);
	while (tmp_str[++j])
	{
		if (tmp_str[j] == '$' && tmp_str[j + 1] == '?')
			add_it(&buffer, &i, &j, vars);
		buffer[i] = tmp_str[j];
		i++;
	}
	buffer[i] = '\0';
	new_str = ft_strdup_a(buffer);
	free(*str);
	free(buffer);
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
	char	*buffer;
	char	*new_str;
	char	*tmp_str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	tmp_str = *str;
	buffer = ft_calloc(sizeof(char), 1024);
	while (tmp_str[++j])
	{
		if (tmp_str[j] == '$')
		{
			new_str = get_the_thing(tmp_str, &j, vars);
			expend_it((char **)&buffer, &i, &new_str);
		}
		else
			buffer[i] = tmp_str[j];
		i++;
	}
	buffer[i] = '\0';
	new_str = ft_strdup_a(buffer);
	free(*str);
	free(buffer);
	*str = new_str;
}

void	improved_expend(char **str, t_list *env, t_vars *vars)
{
	(void)env;
	just_add_exit_code(str, vars);
	expend_the_else(str, vars);
}
