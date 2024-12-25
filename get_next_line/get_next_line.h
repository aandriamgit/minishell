/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:03:06 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:24:16 by aandriam         ###   ########.fr       */
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
