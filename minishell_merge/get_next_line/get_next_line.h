/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:03:06 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/11 15:58:29 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../utils/lib/lib.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*join_them(char *new_buff, char *temp);
char	have_nl(char *buffer);
char	*get_next_line(int fd);

#endif
