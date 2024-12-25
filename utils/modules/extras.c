/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:52:41 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:24:33 by aandriam         ###   ########.fr       */
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

	mini_cmd = ft_strjoin_a("/", cmd);
	path = test_path(getenv("PATH"), mini_cmd);
	if (path)
	{
		free(path);
		return (1);
	}
	ft_perror_soft(cmd, "command not found\n", vars, 127);
	return (0);
}
