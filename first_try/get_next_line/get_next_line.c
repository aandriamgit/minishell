/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:07:01 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/01 14:11:24 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*mini_buffer_gen(char *temp, char *new_buff, char type)
{
	if (type == 'a')
	{
		free(temp);
		free(new_buff);
		return (NULL);
	}
	else
	{
		free(temp);
		return (new_buff);
	}
}

static char	*buffer_gen(int fd, char *buffer)
{
	char	*temp;
	char	*new_buff;
	int		recep;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == 0)
		return (NULL);
	new_buff = malloc(sizeof(char));
	new_buff[0] = '\0';
	if (buffer)
	{
		new_buff = join_them(new_buff, buffer);
		free(buffer);
	}
	while (have_nl(new_buff) == 'n')
	{
		recep = read(fd, temp, BUFFER_SIZE);
		if ((recep == 0 && new_buff[0] == '\0') || recep == -1)
			return (mini_buffer_gen(temp, new_buff, 'a'));
		else if (recep == 0)
			return (mini_buffer_gen(temp, new_buff, 'b'));
		temp[recep] = '\0';
		new_buff = join_them(new_buff, temp);
	}
	return (mini_buffer_gen(temp, new_buff, 'b'));
}

static char	*draw_the_line(char *buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	if (have_nl(buffer) == 'n')
	{
		new_line = ft_substr(buffer, 0, ft_strlen(buffer));
		return (new_line);
	}
	while (buffer[i] != '\n')
		i++;
	new_line = ft_substr(buffer, 0, (i + 1));
	return (new_line);
}

static char	*purification(char *buffer)
{
	char	*new_buff;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	if (have_nl(buffer) == 'n')
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	while (buffer[i] != '\n')
		i++;
	new_buff = ft_substr(buffer, (i + 1), ft_strlen(buffer));
	free(buffer);
	buffer = NULL;
	return (new_buff);
}

char	*get_next_line(int fd)
{
	char		*the_line;
	static char	*buffer;

	if (fd == -99)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (have_nl(buffer) == 'n')
		buffer = buffer_gen(fd, buffer);
	the_line = draw_the_line(buffer);
	buffer = purification(buffer);
	return (the_line);
}
