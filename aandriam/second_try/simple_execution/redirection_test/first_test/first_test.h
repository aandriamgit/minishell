/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:07:51 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/19 17:44:15 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../redirection_test.h"

void	create_pipe(int *pipe_fd);
void	exec_cmd(t_command *cmd, int input_fd, int output_fd);
void	error_protocol(char *str);
void	ft_execve_lol(char *cmd, char **argv);
