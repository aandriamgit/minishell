/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:05 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/21 16:51:14 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(t_vars *vars)
{
	char	*home_dir;
	char	**big_param;
	int		fd;

	home_dir = getenv("HOME");
	vars->log_dir = ft_strjoin(home_dir, "/.minishell_log");
	big_param = malloc(sizeof(char *) * 3);
	big_param[0] = ft_strdup("mkdir");
	big_param[1] = ft_strdup(vars->log_dir);
	big_param[2] = NULL;
	vars->history_dir = ft_strjoin(vars->log_dir, "/.minishell_history");
	fd = open(vars->history_dir, O_WRONLY | O_APPEND | O_CREAT, 0755);
	if (access(vars->log_dir, F_OK) == 0)
		return ;
	else
		execve("/bin/mkdir", big_param, NULL);
	close(fd);
}

void	interpret(char **input)
{
	*input = ft_readline("minishell > ");
	ft_add_history(*input);
	if (ft_strncmp(*input, "exit\n") == 0)
	{
		free(*input);
		exit(1);
	}
}

void	path_execution(char *input)
{
	(void)input;
	ft_putstr_fd("path_execution\n", 1);
}

void	simple_execution(char *input)
{
	(void)input;
	ft_putstr_fd("simple_execution\n", 1);
}

int	main(int argc, char **argv)
{
	char	*input;
	t_vars	vars;

	(void)argv;
	if (argc == 1)
	{
		shell_init(&vars);
		while (1)
		{
			interpret(&input);
			if (input[0] == '.' || input[0] == '/')
				path_execution(input);
			else
				simple_execution(input);
			free(input);
		}
	}
	else
		printf("[Error] minishell doesn't need arguments\n");
	return (0);
}
