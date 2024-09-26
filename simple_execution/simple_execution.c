/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:45:22 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/26 18:58:46 by aandriam         ###   ########.fr       */
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

void	p_test(t_vars *vars)
{
	t_pipe	*v_one;
	char	*buff;

	vars->pipe = parsing_test();
	v_one = vars->pipe;
	while (v_one->next)
	{
		buff = get_output(v_one, vars);
		v_one = v_one->next;
		exit(0);
		use_as_input(&buff, v_one);
	}
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
	// exec_special_cmd(vars);
	else
	{
		big_param = ft_split(vars->input, ' ');
		cmd = ft_strjoin("/", big_param[0]);
		path = test(getenv("PATH"), cmd);
		fork_exec_nopipe(path, big_param, vars);
		terminate_nopipe(path, &big_param);
	}
}
