/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:25:12 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/04 10:09:42 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_n.h"

static int	is_numeric(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit_a(arg[i]))
			return (0);
		i++;
	}
	if (i == 1)
		return (0);
	return (1);
}

static void	good_bye(t_command_a *cmd, t_vars *vars)
{
	int	nbr;

	nbr = ft_atoi_a(cmd->args[1]);
	if (nbr >= 0 && nbr <= 255)
		ft_perror_exit(NULL, NULL, vars, nbr);
	else
		ft_perror_exit(NULL, NULL, vars, (nbr % 256));
}

static void	extras(t_command_a *cmd, t_vars *vars)
{
	ft_putstr_fd_a("exit\n", STDOUT_FILENO);
	if (cmd->args[1])
	{
		if (!is_numeric(cmd->args[1]))
		{
			ft_perror_soft(cmd->args[1], "numeric argument required\n", vars,
				2);
			show_errors(vars);
			ft_perror_exit(NULL, NULL, vars, 2);
		}
		if (cmd->args[2])
			ft_perror_soft("exit", "too many arguments\n", vars, 1);
		else
			good_bye(cmd, vars);
	}
	else
		ft_perror_exit(NULL, NULL, vars, vars->exit_code_int);
}

void	ft_exit_n(t_command_a *cmd, t_vars *vars)
{
	int	flag;
	int	save_stdout;
	int	save_stdin;

	flag = 0;
	save_stdout = dup(STDOUT_FILENO);
	save_stdin = dup(STDIN_FILENO);
	handle_redir(cmd->redir, vars, &flag);
	if (flag)
		extras(cmd, vars);
	dup2(save_stdout, STDOUT_FILENO);
	dup2(save_stdin, STDIN_FILENO);
	close(save_stdout);
	close(save_stdin);
}