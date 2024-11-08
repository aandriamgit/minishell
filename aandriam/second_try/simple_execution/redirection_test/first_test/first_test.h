/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:07:51 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/08 11:00:00 by aandriam         ###   ########.fr       */
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
void	ft_echo(t_command *cmd);
void	ft_cd(t_command *cmd);
void	w_pipe(t_pipe *test_pipe);
void	no_pipe(t_pipe *test_pipe);
void	ft_echo_chill(t_command *cmd);
void	ft_cd_chill(t_command *cmd);
