/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:07:51 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/20 11:36:25 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../redirection_test.h"

void	handle_cmd(t_pipe test_pipe, t_command *cmd, int input_fd,
			int output_fd);
void	error_protocol(char *str);
void	ft_execve_lol(char *cmd, char **argv);
void	handle_redir(t_redirection *redir);
void	input_redir(char *file);
void	output_redir(char *file);
void	append_redir(char *file);
void	heredoc_redir(char *file);
