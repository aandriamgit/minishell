/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_bloc_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:39:45 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/28 12:12:17 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/utils.h"
#include "../parsing.h"

int	count_arg(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_cmd	*creat_bloc_cmd(char *str)
{
	char	**split;
	t_cmd	*cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	split = split_quote(str, ' ');
	if (check_quotes(split[0]) == 1)
		rm_quote(&split[0]);
	cmd->cmd = ft_strdup_p(split[0]);
	cmd->arg = malloc(sizeof(char *) * (count_arg(split) + 1));
	if (!(cmd->arg))
		cmd->arg = NULL;
	else
	{
		while (split[i])
		{
			if (check_quotes(split[i]) == 1)
				rm_quote(&split[i]);
			cmd->arg[j] = ft_strdup_p(split[i]);
			j++;
			i++;
		}
		cmd->arg[j] = NULL;
	}
	ft_free_tab(&split);
	return (cmd);
}

t_cmd	*make_cmd(char **str)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd = creat_bloc_cmd(*str);
	return (cmd);
}
