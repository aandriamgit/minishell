/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_test_no_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:05:29 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/01 18:15:06 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_test.h"

int	init_test(t_pipe **p_test)
{
	char	*input;
	char	*tmp;
	char	**splited;

	ft_putstr_fd("\nyou can type ''NULL'' or ctrl+D to valide\n", 1);
	tmp = readline("your cmd > ");
	if (!tmp)
		return (0);
	else if (ft_strncmp(tmp, "NULL\n") == 0)
	{
		free(tmp);
		return (0);
	}
	splited = ft_split(tmp, ' ');
	if (splited[1][0] == '"')
	{
		input = ft_substr(splited[1], 1, (ft_strlen(splited[1]) - 2));
		free(splited[1]);
		splited[1] = input;
	}
	*p_test = gen_pipe_test(gen_cmd(splited[0], splited, NULL, NULL), NULL,
			NULL);
	free(tmp);
	return (1);
}

void	just_do_it(t_pipe *p_test)
{
	exec_t_pipe(p_test);
	free_t_pipe(p_test);
	free_t_pipe_again(&p_test);
}

void	add_input(t_pipe **p_test, char *input)
{
	t_pipe	*tmp;
	t_pipe	*lol;
	t_pipe	*to_add;
	char	**splited;

	splited = ft_split(input, ' ');
	to_add = gen_pipe_test(gen_cmd(splited[0], splited, NULL, NULL), NULL,
			NULL);
	tmp = *p_test;
	while (tmp)
	{
		lol = tmp;
		tmp = tmp->next;
	}
	add_pipe_next(&lol, &to_add);
}
