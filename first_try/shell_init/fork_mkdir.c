/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_mkdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:01:23 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/25 18:01:42 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fork_mkdir(char **big_param)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve("/bin/mkdir", big_param, NULL);
		exit(1);
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("fork error");
}
