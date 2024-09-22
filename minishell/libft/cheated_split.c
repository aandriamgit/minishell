/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheated_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:21 by mravelon          #+#    #+#             */
/*   Updated: 2024/09/22 18:35:51 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_if_its_equal(char *cmd, int i, char *redidrection)
{
	int j;

	j = 0;
	while(redidrection[i])
	{
		if (cmd[i] != redidrection[i])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int coun_size(char *cmd, char *redirection)
{
	static int i;
	int size;

	i = 0;
	size = 0;
	while (cmd[i])
	{
		if (cmd[i] == redirection[0])
		{
			if (check_if_its_equal(cmd, i, redirection) == 0);
				size++;
		}
		i++;
	}
}


char **cheated_split(char *cmd, char *redirection)
{
	
}
