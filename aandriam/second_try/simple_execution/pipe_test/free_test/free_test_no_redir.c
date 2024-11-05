/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_test_no_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:05:29 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/05 16:45:28 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_test.h"

void	show_errors(void)
{
	char	*res;
	char	*tmp;
	char	**args;
	int		pid;

	tmp = ft_strjoin(getenv("HOME"), "/.minishell_log");
	res = ft_strjoin(tmp, "/.err_log");
	pid = fork();
	if (pid == 0)
	{
		args = malloc(sizeof(char *) * 3);
		args[0] = ft_strdup("cat");
		args[1] = res;
		args[2] = NULL;
		if (execve("/bin/cat", args, NULL) == -1)
			ft_perror(NULL, "error execve");
	}
	else if (pid > 0)
	{
		wait(NULL);
		finish_errors(&tmp, &res);
	}
}

static void	init_error(void)
{
	int		fd;
	char	*lol;

	lol = get_err_dir();
	fd = open(lol, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	free(lol);
	close(fd);
}

int	init_test(t_pipe **p_test)
{
	char	*input;
	char	*tmp;
	char	**splited;

	init_error();
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
	if (splited[1] && splited[1][0] == '"')
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

void	just_do_it(t_pipe *p_test, t_vars *vars)
{
	heredoc_supremacy(p_test, vars);
	free_t_pipe(p_test);
	free_t_pipe_again(&p_test);
	show_errors();
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
