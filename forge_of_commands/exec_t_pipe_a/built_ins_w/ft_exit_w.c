/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:49:16 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/05 09:00:24 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins_w.h"

static int	is_numeric(char *arg)
{
	int	i;
	int	n;

	i = 0;
	while (*arg && ft_isspace(*arg))
		arg++;
	n = (*arg == '-');
	arg += (*arg == '-' || *arg == '+');
	if (*arg == '\0')
		return (0);
	while (*arg && *arg == '0')
		arg++;
	while (arg[i] && ft_isdigit_a(arg[i]))
		i++;
	while (arg[i] && ft_isspace(arg[i]))
		i++;
	if (arg[i] != '\0')
		return (0);
	if ((ft_strlen_exit_a(arg) > 19) || ((ft_strlen_exit_a(arg) == 19)
			&& ((n == 1 && ft_strncmp_a(arg, "9223372036854775808") > 0)
				|| (n == 0 && ft_strncmp_a(arg, "9223372036854775807") > 0))))
		return (0);
	return (1);
}

static int	get_nbr(char *arg)
{
	unsigned long long	m;
	int					i;
	int					sign;

	m = 0;
	sign = 1;
	while (*arg && ft_isspace(*arg))
		arg++;
	if (*arg == '-')
		sign = -1;
	arg += (*arg == '-' || *arg == '+');
	i = -1;
	while (arg[++i] && ft_isdigit_a(arg[i]))
		m = m * 10 + arg[i] - '0';
	return ((m * sign) % 256);
}

static void	good_bye(t_command_a *cmd, t_vars *vars)
{
	int	nbr;

	if (cmd->args[1])
	{
		nbr = get_nbr(cmd->args[1]);
		if (nbr >= 0 && nbr <= 255)
			ft_perror_exit(NULL, NULL, vars, nbr);
		else
			ft_perror_exit(NULL, NULL, vars, (nbr % 256));
	}
	else
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
	if (!vars->exit_code_int)
		vars->exit_code_int = download_exit_code(vars);
	handle_redir(cmd->redir, vars, &flag);
	if (flag)
		extras(cmd, vars);
	dup2(save_stdout, STDOUT_FILENO);
	dup2(save_stdin, STDIN_FILENO);
	close(save_stdout);
	close(save_stdin);
}
