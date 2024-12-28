/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:52:41 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/28 09:52:11 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*get_file_dir(char *file)
{
	char	*res;
	char	*lol;

	lol = ft_strrchr_a(file, '/');
	if (!lol)
		return (NULL);
	lol++;
	res = ft_substr_a(file, 0, (ft_strlen_a(file) - ft_strlen_a(lol)));
	return (res);
}

int	cmd_check(char *cmd, t_vars *vars)
{
	char	*path;
	char	*mini_cmd;
	char	*mini_path;

	if (cmd)
	{
		mini_cmd = ft_strjoin_a("/", cmd);
		mini_path = ft_getenv("PATH", vars->env);
		path = test_path(mini_path, mini_cmd);
		free(mini_path);
		if (path)
		{
			free(path);
			return (1);
		}
		ft_perror_soft(cmd, "command not found\n", vars, 127);
		return (0);
	}
	else
		return (0);
}
