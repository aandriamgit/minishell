/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_supremacy.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:27:59 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:30:44 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../forge_of_commands.h"

int		have_heredoc(t_pipe_a *test_pipe);
char	*get_eof(t_pipe_a *test_pipe);
void	init_heredoc(t_vars *vars, char *eof);
void	purify_from_heredoc(t_pipe_a **test_pipe, char *heredoc_dir, int nb);
void	print_heredoc(t_vars *vars, char *eof, int heredoc_type,
			int fd_heredoc);
