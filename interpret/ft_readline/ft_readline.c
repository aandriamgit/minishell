/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:02:09 by aandriam          #+#    #+#             */
/*   Updated: 2024/09/23 16:27:58 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*char_to_string(char c)
{
	char	*tmp;

	tmp = malloc(sizeof(char));
	if (tmp)
	{
		tmp[0] = c;
		tmp[1] = '\0';
		return (tmp);
	}
	return (NULL);
}

char	*append(char *clean, char c)
{
	int		i;
	char	*new;
	char	*tmp;

	i = 0;
	if (clean == NULL)
	{
		new = malloc(sizeof(char));
		if (!new)
			exit(EXIT_FAILURE);
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	while (clean[i])
		i++;
	tmp = char_to_string(c);
	new = ft_strjoin(clean, tmp);
	free(tmp);
	return (new);
}

char	*ft_readline(char *prompt)
{
	char			c;
	struct termios	orig_tty;
	char			*clean;

	ft_putstr_fd(prompt, 1);
	clean = NULL;
	set_non_canonical_mode();
	while (1)
	{
		read(0, &c, 1);
		if (c == '\n')
			break ;
		write(1, &c, 1);
		clean = append(clean, c);
	}
	ft_putstr_fd(clean, 1);
	tcsetattr(STDIN_FILENO, TCSANOW, &orig_tty);
	return (clean);
}
