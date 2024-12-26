/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pipe_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:53:01 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:22:52 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void	print_cmd(t_command_a *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		while (cmd->args[i])
		{
			ft_putstr_fd_a(cmd->args[i], 1);
			ft_putstr_fd_a(" ", 1);
			i++;
		}
		cmd = cmd->next;
	}
}

static void	print_redir(t_redirection_a *redir)
{
	while (redir)
	{
		ft_putstr_fd_a(redir->type, 1);
		ft_putstr_fd_a(" ", 1);
		ft_putstr_fd_a(redir->file, 1);
		ft_putstr_fd_a(" ", 1);
		redir = redir->next;
	}
}

void	ft_print_pipe_a(t_pipe_a *tmp)
{
	t_pipe_a	*voyager_one;

	ft_putstr_fd_a("()--() ", 1);
	voyager_one = tmp;
	while (voyager_one)
	{
		print_cmd(voyager_one->cmd);
		print_redir(voyager_one->cmd->redir);
		voyager_one = voyager_one->next;
		if (voyager_one)
			ft_putstr_fd_a("| ", 1);
	}
	ft_putstr_fd_a("()--() ", 1);
	ft_putstr_fd_a("\n", 1);
}
