/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:45:22 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/25 16:31:44 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	terminate_nopipe(char *path, char ***big_param)
{
	free(path);
	free_res(big_param);
}

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

void	pipe_exec(t_vars *vars)
{
	(void)vars->input;
	return ;
}

void	no_pipe_exec(t_vars *vars)
{
	char	**big_param;
	char	*path;
	char	*cmd;

	if (is_special_cmd(vars))
		exec_special_cmd(vars);
	else
	{
		big_param = ft_split(vars->input, ' ');
		cmd = ft_strjoin("/", big_param[0]);
		path = test(getenv("PATH"), cmd);
		fork_exec_nopipe(path, big_param, vars);
		terminate_nopipe(path, &big_param);
	}
}
