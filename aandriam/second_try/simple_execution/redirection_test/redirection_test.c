/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:52:58 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/22 11:16:45 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection_test.h"

void	first_test(char *cmd, char *type, char *file)
{
	char			**big_param;
	t_pipe			*test_pipe;
	t_redirection	*redir;

	big_param = malloc(sizeof(char **) * 2);
	if (!big_param)
		return ;
	test_pipe = malloc(sizeof(t_pipe));
	if (!test_pipe)
		return ;
	big_param[0] = cmd;
	big_param[1] = NULL;
	redir = gen_redir(type, file, NULL);
	test_pipe->cmd = gen_cmd(cmd, big_param, redir, NULL);
	test_pipe->next = NULL;
	test_pipe->prev = NULL;
	exec_t_pipe(test_pipe);
	free_t_pipe(test_pipe);
	free(test_pipe);
}

void	input_redir_test(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("redirection test with 'cat < input.txt'\n", 1);
	first_test(ft_strdup("cat"), ft_strdup("<"), ft_strdup("input.txt"));
	ft_putstr_fd("\nredirection test with 'cat < simple_execution/input.txt'\n",
		1);
	first_test(ft_strdup("cat"), ft_strdup("<"),
		ft_strdup("simple_execution/input.txt"));
	ft_putstr_fd("\nredirection test with 'ls < not_existing_file.txt'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup("<"),
		ft_strdup("not_existing_file.txt"));
	ft_putstr_fd("\nredirection test with 'cat < no_permission.txt'\n", 1);
	first_test(ft_strdup("cat"), ft_strdup("<"),
		ft_strdup("no_permission.txt"));
	ft_putstr_fd("\nredirection test with 'cat < empty.txt'\n", 1);
	first_test(ft_strdup("cat"), ft_strdup("<"), ft_strdup("empty.txt"));
	ft_putstr_fd("\nredirection test with 'cat < /not/a/directory/test.txt'\n",
		1);
	first_test(ft_strdup("cat"), ft_strdup("<"),
		ft_strdup("/not/a/directory/test.txt"));
	ft_putstr_fd("\nredirection test with 'cat < /root'\n", 1);
	first_test(ft_strdup("cat"), ft_strdup("<"), ft_strdup("/root"));
	ft_putstr_fd("\nredirection test with 'cat < simple_execution'\n", 1);
	first_test(ft_strdup("cat"), ft_strdup("<"), ft_strdup("simple_execution"));
}

void	output_redir_test(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\nredirection test with 'ls > output.txt'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup(">"), ft_strdup("output.txt"));
	ft_putstr_fd("\nredirection test with 'ls > simple_execution/output.txt\n",
		1);
	first_test(ft_strdup("ls"), ft_strdup(">"),
		ft_strdup("simple_execution/output.txt"));
	ft_putstr_fd("\nredirection test with 'ls > /root/test.txt'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup(">"), ft_strdup("/root/output.txt"));
	ft_putstr_fd("\nredirection test with 'ls > no_permission.txt'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup(">"), ft_strdup("no_permission.txt"));
	ft_putstr_fd("\nredirection test with 'ls > not/a/directory/test.txt'\n",
		1);
	first_test(ft_strdup("ls"), ft_strdup(">"),
		ft_strdup("not/a/directory/test.txt"));
	ft_putstr_fd("\nredirection test with 'ls > simple_execution'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup(">"), ft_strdup("simple_execution"));
}

void	append_redir_test(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("redirection test with 'ls >> output_append.txt'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup(">>"),
		ft_strdup("output_append.txt"));
	ft_putstr_fd("\nredir test 'ls >> simple_execution/output_append.txt\n", 1);
	first_test(ft_strdup("ls"), ft_strdup(">>"),
		ft_strdup("simple_execution/output_append.txt"));
	ft_putstr_fd("\nredirection test with 'ls >> /root/test.txt'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup(">>"), ft_strdup("/root/output.txt"));
	ft_putstr_fd("\nredirection test with 'ls >> no_permission.txt'\n", 1);
	first_test(ft_strdup("ls"), ft_strdup(">>"),
		ft_strdup("no_permission.txt"));
	ft_putstr_fd("\nredirection test with 'ls >> not/a/directory/test.txt'\n",
		1);
	first_test(ft_strdup("ls"), ft_strdup(">>"),
		ft_strdup("not/a/directory/test.txt"));
}

void	multi_redir_test(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("redirection test with 'sort < unsorted.txt > sorted.txt'\n",
		1);
	exec_combined_redir(ft_strdup("sort"), ft_strdup("< unsorted.txt"),
		ft_strdup("> sorted.txt"));
	ft_putstr_fd("\nredir test 'sort < unsorted.txt >> append_sorted.txt'\n",
		1);
	exec_combined_redir(ft_strdup("sort"), ft_strdup("< unsorted.txt"),
		ft_strdup(">> append_sorted.txt"));
	ft_putstr_fd("\nredir test 'echo bonjour >> file_one.txt > file_two.txt'\n",
		1);
	exec_combined_redir(ft_strdup("echo bonjour"), ft_strdup(">> file_one.txt"),
		ft_strdup("> file_two.txt"));
	ft_putstr_fd("\nredir test 'cat < not_existing_file.txt > cantexist.txt'\n",
		1);
	exec_combined_redir(ft_strdup("cat"), ft_strdup("< not_existing_file.txt"),
		ft_strdup("> cantexist.txt"));
	ft_putstr_fd("\nredir test 'cat < no_permission.txt > cantexist.txt'\n", 1);
	exec_combined_redir(ft_strdup("cat"), ft_strdup("< no_permission.txt"),
		ft_strdup("> cantexist.txt"));
}
