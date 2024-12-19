/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:56:13 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/19 13:36:12 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_vars(t_vars *vars)
{
	free(vars->history_dir);
	free(vars->log_dir);
	free(vars->heredoc_dir);
	free(vars->exit_code_dir);
	free(vars->stderr_a);
	free(vars->stderr_log);
	free(vars->quote_dir);
	if (vars->input)
	{
		free(vars->input);
		vars->input = NULL;
	}
	ft_free_t_list(&vars->env);
	if (vars->cmd)
	{
		free_pipe(&vars->cmd);
		vars->cmd = NULL;
	}
}

void	exit_protocol(t_vars *vars, char **input, int nbr)
{
	free_vars(vars);
	if (*input != NULL)
		free(*input);
	exit(nbr);
}

static char	*emergency_prompt(void)
{
	char	*res;

	res = ft_strdup_a("emergency_prompt> ");
	return (res);
}

char	*nice_prompt(t_vars *vars)
{
	char	*tmp;
	char	*lol;
	char	buffer[1024];

	(void)vars;
	if (getcwd(buffer, 1024))
	{
		if (!vars->exit_code_int)
			vars->exit_code_int = download_exit_code(vars);
		lol = ft_strdup_a("\001\033[38;2;166;227;161m\022");
		tmp = ft_strjoin_free_a(lol,
				"\001╭\002\001\033[38;2;148;226;213m\002 ");
		tmp = ft_strjoin_free_a(tmp, buffer);
		tmp = ft_strjoin_free_a(tmp, "\001\033[38;2;137;180;250m\002  \n");
		if (!vars->exit_code_int)
			tmp = ft_strjoin_free_a(tmp, "\001\033[38;2;137;180;250m\002");
		else
			tmp = ft_strjoin_free_a(tmp, "\001\033[38;2;243;139;168m\002");
		tmp = ft_strjoin_free_a(tmp, "\001╰\002");
		tmp = ft_strjoin_free_a(tmp, "\001\002\001\033[0m\002 ");
	}
	else
		tmp = emergency_prompt();
	return (tmp);
}

void	ft_add_history(char *input, t_vars *vars)
{
	int	fd;

	if (input[0] != '\n')
	{
		fd = open(vars->history_dir, O_RDWR | O_APPEND);
		if (fd == -1)
			exit(1);
		ft_putstr_fd_a(input, fd);
		ft_putstr_fd_a("\n", fd);
		add_history(input);
	}
}
