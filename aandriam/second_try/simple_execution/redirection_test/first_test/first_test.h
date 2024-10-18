/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:50:24 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/18 11:42:14 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../redirection_test.h"

int		create_pipe(int *pipe_fd);
pid_t	create_child(t_command *cmd, int *pipe_fd, t_pipe *next);
int		is_last(t_pipe *next);
void	wait_for_children(void);
void	input_redir(char *file);
pid_t	first_in_line(t_command *cmd);
