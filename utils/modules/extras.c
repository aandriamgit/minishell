/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:52:41 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/05 13:10:13 by aandriam         ###   ########.fr       */
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

	path = NULL;
	mini_path = ft_getenv("PATH", vars->env);
	if (cmd && mini_path)
	{
		mini_cmd = ft_strjoin_a("/", cmd);
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
	{
		ft_perror_soft(cmd, "command not found\n", vars, 127);
		return (0);
	}
}

void	extra_check_void_pipe(char *str, int *i)
{
	while (str[*i] && str[*i] != '|')
	{
		if (str[*i] == '\'' || str[*i] == '\"')
			skip_x(i, str, str[*i]);
		else
			*i = *i + 1;
	}
}

char	*emergency_prompt_lol(void)
{
	char	*lol;
	char	*tmp;

	lol = ft_strdup_a("\001\033[38;2;166;227;161m\022");
	tmp = ft_strjoin_free_a(lol, "\001╭\002\001\033[38;2;148;226;213m\002 ");
	tmp = ft_strjoin_free_a(tmp, " You are into the Abyss");
	tmp = ft_strjoin_free_a(tmp, "\001\033[38;2;137;180;250m\002  \n");
	tmp = ft_strjoin_free_a(tmp, "\001\033[38;2;137;180;250m\002");
	tmp = ft_strjoin_free_a(tmp, "\001╰\002");
	tmp = ft_strjoin_free_a(tmp, "\001\002\001\033[0m\002 ");
	return (tmp);
}
