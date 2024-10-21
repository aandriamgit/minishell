/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:07:51 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/21 16:09:13 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../redirection_test.h"

void	handle_cmd(t_pipe test_pipe, t_command *cmd, int input_fd,
			int output_fd);
void	error_protocol(char *str);
void	handle_redir(t_redirection *redir);
void	input_redir(char *file);
void	output_redir(char *file);
void	append_redir(char *file);
void	heredoc_redir(char *file);
char	*get_file_dir(char *file);
