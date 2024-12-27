/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:54:34 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/27 14:17:43 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "dep/dep.h"

static int	found_it(char *tmp, char *parameter)
{
	int	i;

	i = 0;
	while (parameter[i])
	{
		if (parameter[i] == '=')
		{
			if (ft_strncmp_ap(tmp, parameter, i) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

static void	replace_it(char **to_replace, char *parameter)
{
	int		i;
	char	*new;

	i = 0;
	while (parameter[i])
	{
		if (parameter[i] == '=')
		{
			new = ft_substr_ap(parameter, i + 1, ft_strlen_ap(parameter));
			if (!new)
				return ;
			free(*to_replace);
			*to_replace = new;
		}
		i++;
	}
}

static void	mini_expend_a(char **str, t_list *env)
{
	char	*to_replace;
	char	*tmp;
	t_list	*voyager_one;

	tmp = *str;
	if (tmp && tmp[1] != '"')
	{
		to_replace = ft_strdup_ap("");
		voyager_one = env;
		while (voyager_one)
		{
			if (found_it(tmp, voyager_one->cmd))
			{
				replace_it(&to_replace, voyager_one->cmd);
				break ;
			}
			voyager_one = voyager_one->next;
		}
		free(*str);
		*str = to_replace;
	}
}

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


int	count_pp(char **str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void	expend(char	**str, t_list *env, t_vars	*vars)
{
	char	**splited_a;
	char	*new;
	char	*exit_code;

	exit_code = gen_exit_code(vars);
	export_with_arg(&env, exit_code);
	free(exit_code);
	if ((*str)[0] == '$' && (*str)[1] == '\0')
	{
		free(*str);
		*str = ft_strdup_p("");
		unset_p(&env, "?");
		return ;
	}
	splited_a = ft_split_aa(*str, '$');
	if (count_pp(splited_a) == 1)
		mini_expend_a(&splited_a[0], env);
	else
		mini_expend_a(&splited_a[1], env);
	new = ft_strjoin_space(&splited_a);
	free(*str);
	*str = new;
	unset_p(&env, "?");
}

void	improved_expend(char **str, t_list *env, t_vars *vars)
{
	(void)env;
	just_add_exit_code(str, vars);
	expend_the_else(str, vars);
}
