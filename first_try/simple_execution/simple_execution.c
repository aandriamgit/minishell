/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:45:22 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/11 10:56:38 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	have_pipe(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->input[i])
	{
		if (vars->input[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

void	cmd_test(t_vars *vars)
{
	if (ft_strncmp(vars->input, "pipe_test") == 0)
		p_test(vars);
	else if (ft_strncmp(vars->input, "redirection_test") == 0)
		redir_test(vars);
}

void	pipe_exec(t_vars *vars)
{
	(void)vars;
}

void	no_pipe_exec(t_vars *vars)
{
	char	**big_param;
	char	*path;
	char	*cmd;

	if (is_special_cmd(vars))
		ft_putstr_fd("is_special_cmd", 1);
	else
	{
		big_param = ft_split(vars->input, ' ');
		cmd = ft_strjoin("/", big_param[0]);
		path = test(getenv("PATH"), cmd);
		fork_exec_nopipe(path, big_param, vars);
		free_res(&big_param);
		free(path);
	}
}
