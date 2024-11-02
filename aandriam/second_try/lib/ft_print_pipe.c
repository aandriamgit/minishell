/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:53:01 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/02 18:19:29 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "lib.h"

void	print_cmd(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		while (cmd->args[i])
		{
			ft_putstr_fd(cmd->args[i], 1);
			ft_putstr_fd(" ", 1);
			i++;
		}
		cmd = cmd->next;
	}
}

void	print_redir(t_redirection *redir)
{
	int	i;

	i = 0;
	while (redir)
	{
		ft_putstr_fd(redir->type, 1);
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(redir->file, 1);
		ft_putstr_fd(" ", 1);
		redir = redir->next;
	}
}

void	ft_print_pipe(t_pipe *tmp)
{
	t_pipe	*voyager_one;

	ft_putstr_fd("()--() ", 1);
	voyager_one = tmp;
	while (voyager_one)
	{
		print_cmd(voyager_one->cmd);
		print_redir(voyager_one->cmd->redir);
		voyager_one = voyager_one->next;
		if (voyager_one)
			ft_putstr_fd("| ", 1);
	}
	ft_putstr_fd("()--() ", 1);
	ft_putstr_fd("\n", 1);
}
