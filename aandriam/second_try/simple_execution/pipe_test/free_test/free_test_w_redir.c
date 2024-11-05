/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_test_w_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:47:46 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/05 16:09:38 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_test.h"

void	init_err(t_vars *vars)
{
	int	fd;

	fd = open(vars->err, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	close(fd);
}

void	add_redir_end(t_redirection **res, t_redirection **to_add)
{
	t_redirection	*voyager_one;
	t_redirection	*tmp;

	voyager_one = *res;
	tmp = voyager_one;
	while (voyager_one)
	{
		tmp = voyager_one;
		voyager_one = voyager_one->next;
	}
	if (tmp)
		tmp->next = *to_add;
	else
		*res = *to_add;
}

t_redirection	*getting_redir(void)
{
	t_redirection	*res;
	t_redirection	*to_add;
	char			*input;
	char			**splited;

	res = NULL;
	to_add = NULL;
	while (1)
	{
		input = readline("add redir? :: ");
		if (!input || ft_strncmp(input, "NULL") == 0)
		{
			if (input)
			{
				splited = ft_split(input, ' ');
				free(input);
				to_add = gen_redir(splited[0], splited[1], NULL);
				add_redir_end(&res, &to_add);
			}
			return (res);
		}
		splited = ft_split(input, ' ');
		free(input);
		to_add = gen_redir(ft_strdup(splited[0]), ft_strdup(splited[1]), NULL);
		ft_free_all(&splited);
		add_redir_end(&res, &to_add);
	}
}

void	add_pipe_end(t_pipe **p_test, t_pipe **to_add)
{
	t_pipe	*voyager_one;
	t_pipe	*tmp;

	voyager_one = *p_test;
	tmp = voyager_one;
	while (voyager_one)
	{
		tmp = voyager_one;
		voyager_one = voyager_one->next;
	}
	if (tmp)
		tmp->next = *to_add;
	else
		*p_test = *to_add;
}

void	add_input_w_redir(char *input, t_pipe **p_test)
{
	t_pipe			*to_add;
	t_command		*cmd;
	t_redirection	*redir;
	char			**splited;

	if (input != NULL)
	{
		splited = ft_split(input, ' ');
		redir = getting_redir();
		cmd = gen_cmd(splited[0], splited, redir, NULL);
		to_add = gen_pipe_test(cmd, NULL, NULL);
		add_pipe_end(p_test, &to_add);
	}
}
