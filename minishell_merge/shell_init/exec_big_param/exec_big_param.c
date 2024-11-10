/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_big_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:48:49 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/09 17:24:39 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../shell_init.h"

char	*test(char *path, char *input)
{
	char	**res;
	char	*tmp;
	int		i;

	i = 0;
	res = ft_split(path, ':');
	while (res[i])
	{
		tmp = ft_strjoin(res[i], input);
		if ((access(tmp, X_OK)) == 0)
		{
			ft_free_all(&res);
			free(input);
			input = NULL;
			return (tmp);
		}
		free(tmp);
		i++;
	}
	free(input);
	ft_free_all(&res);
	input = NULL;
	return (NULL);
}

void	exec_big_param(char **big_param)
{
	char	*path;
	char	*cmd;

	cmd = ft_strjoin("/", big_param[0]);
	path = test(getenv("PATH"), cmd);
	if (!path)
	{
		ft_putstr_fd("error : command not found: ", 1);
		ft_putstr_fd(big_param[0], 1);
		ft_putstr_fd("\n", 1);
		return ;
	}
	else
		ft_execve(path, big_param);
	free(path);
}
