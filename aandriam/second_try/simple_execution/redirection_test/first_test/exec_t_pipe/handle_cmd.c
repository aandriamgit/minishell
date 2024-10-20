/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:21:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/20 09:52:51 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../first_test.h"

char	*test_path_lol(char *path, char *input)
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

void	ft_execve_lol(char *cmd, char **args)
{
	char	*path;
	char	*mini_cmd;

	mini_cmd = ft_strjoin("/", cmd);
	path = test_path_lol(getenv("PATH"), mini_cmd);
	if (path)
		execve(path, args, NULL);
	else
	{
		ft_putstr_fd("error : command not found: ", 1);
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("\n", 1);
		free(path);
		free(mini_cmd);
		return ;
	}
}

void	handle_redir(t_redirection *redir)
{
	while (redir)
	{
		if (ft_strncmp(redir->type, "<") == 0)
			input_redir(redir->file);
		else if (ft_strncmp(redir->type, ">") == 0)
			output_redir(redir->file);
		else if (ft_strncmp(redir->type, ">>") == 0)
			append_redir(redir->file);
		else if (ft_strncmp(redir->type, "<<") == 0)
			heredoc_redir(redir->file);
		redir = redir->next;
	}
}
