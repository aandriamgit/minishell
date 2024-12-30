/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:14:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/30 15:34:32 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

static int	is_numeric(char *arg)
{
	int	i;
	int	n;

	i = -1;
	n = (*arg == '-');
	arg += (*arg == '-' || *arg == '+');
	while (arg[++i])
	{
		if (!ft_isdigit_a(arg[i]))
			return (0);
	}
	if ((ft_strlen_a(arg) > 19) || ((ft_strlen_a(arg) == 19) && ((n == 1
					&& ft_strncmp_a(arg, "9223372036854775808") > 0) || (n == 0
					&& ft_strncmp_a(arg, "9223372036854775807") > 0))))
		return (0);
	return (1);
}

static void	good_bye(t_command_a *cmd, t_vars *vars)
{
	int	nbr;

	if (cmd->args[1])
	{
		nbr = ft_atoi_a(cmd->args[1]);
		if (nbr >= 0 && nbr <= 255)
			ft_perror_exit(NULL, NULL, vars, nbr);
		else
			ft_perror_exit(NULL, NULL, vars, (nbr % 256));
	}
	ft_perror_exit(NULL, NULL, vars, 0);
}

static void	extras(t_command_a *cmd, t_vars *vars)
{
	ft_putstr_fd_a("exit\n", STDOUT_FILENO);
	if (cmd->args[1])
	{
		if (!is_numeric(cmd->args[1]))
		{
			ft_perror_exit(cmd->args[0], "numeric argument required\n", vars,
				2);
			show_errors(vars);
			ft_perror_exit(NULL, NULL, vars, 2);
		}
		else if (cmd->args[2])
			ft_perror_exit("exit", "too many arguments\n", vars, 1);
		else
			good_bye(cmd, vars);
	}
	else
		ft_perror_exit(NULL, NULL, vars, vars->exit_code_int);
}

void	ft_exit_w(t_command_a *cmd, t_vars *vars)
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
