/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:42:32 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/10 18:07:56 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forge_of_commands.h"

static void	extras(char **splited, char **input, t_redirection_a **to_add,
		t_redirection_a **res)
{
	splited = ft_split_a(*input, ' ');
	free(*input);
	*to_add = gen_redir(ft_strdup_a(splited[0]), ft_strdup_a(splited[1]), NULL);
	ft_free_tab(&splited);
	add_redir_end(res, to_add);
}

static t_redirection_a	*getting_redir(void)
{
	t_redirection_a	*res;
	t_redirection_a	*to_add;
	char			*input;
	char			**splited;

	res = NULL;
	to_add = NULL;
	while (1)
	{
		input = readline("add redir? :: ");
		if (!input || ft_strncmp_a(input, "NULL") == 0)
		{
			if (input)
			{
				splited = ft_split_a(input, ' ');
				free(input);
				to_add = gen_redir(splited[0], splited[1], NULL);
				add_redir_end(&res, &to_add);
			}
			return (res);
		}
		extras(splited, &input, &to_add, &res);
	}
}

static void	append_input_pipe_a(char **input, t_pipe_a **pipe_a)
{
	t_pipe_a		*to_add;
	t_command_a		*cmd;
	t_redirection_a	*redir;
	char			**splited;

	if (input != NULL)
	{
		splited = ft_split_a(*input, ' ');
		redir = getting_redir();
		cmd = gen_cmd(splited[0], splited, redir, NULL);
		to_add = gen_pipe_a(cmd, NULL, NULL);
		add_pipe_end(pipe_a, &to_add);
		free(*input);
	}
}

void	custom_prompt(t_vars *vars, t_pipe_a **pipe_a)
{
	char	*input;

	ft_putstr_fd_a("\n\n[]--[]u can input custom prompt[]--[]\n\n", 1);
	while (1)
	{
		input = readline("your cmd &> ");
		if (!input || ft_strncmp_a(input, "NULL") == 0)
		{
			if (input)
				free(input);
			ft_print_pipe_a(*pipe_a);
			return ;
		}
		append_input_pipe_a(&input, pipe_a);
	}
}
