/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:34:06 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/25 13:39:26 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pipe *binary_tree(char *format_cmd)
{
	t_pipe *cmd;

	cmd = down_pipe(format_cmd);
	return(cmd);
}