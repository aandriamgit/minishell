/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:56:13 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/30 16:20:46 by aandriam         ###   ########.fr       */
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
	close_all_fds();
	if (*input != NULL)
		free(*input);
	exit(nbr);
}

static char	*custom_prompt_interpret(t_vars *vars)
{
	char	*tmp;
	char	*lol;
	char	buffer[1024];

	if (getcwd(buffer, 1024))
	{
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
		tmp = ft_strdup_a("minishell> ");
	return (tmp);
}

char	*nice_prompt(t_vars *vars)
{
	char	*tmp;

	if (!vars->exit_code_int)
		vars->exit_code_int = download_exit_code(vars);
	if (vars->custom_prompt)
		tmp = custom_prompt_interpret(vars);
	else
		tmp = ft_strdup_a("minishell> ");
	return (tmp);
}

void	ft_add_history(char *input, t_vars *vars)
{
	int	fd;

	if (input[0] != '\n')
	{
		fd = open(vars->history_dir, O_RDWR | O_APPEND);
		if (fd == -1)
		{
			close(fd);
			exit(1);
		}
		ft_putstr_fd_a(input, fd);
		ft_putstr_fd_a("\n", fd);
		add_history(input);
		close(fd);
	}
}
