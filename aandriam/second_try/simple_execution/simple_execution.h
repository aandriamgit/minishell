/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:53:13 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/22 18:32:16 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_EXECUTION_H
# define SIMPLE_EXECUTION_H

# include "../minishell.h"

void	first_test(char *cmd, char *type, char *file);
void	input_redir_test(char *str);
void	output_redir_test(char *str);
void	append_redir_test(char *str);
void	multi_redir_test(char *str);
void	exec_combined_redir(char *cmd, char *first_redir, char *next_redir);
void	heredoc_redir_test(char *str, t_vars *vars);
int		have_heredoc(t_pipe *test_pipe);
void	heredoc_supremacy(t_pipe *test_pipe, t_vars *vars);
void	init_heredoc(t_vars *vars, char *eof);
char	*get_eof(t_pipe *test_pipe);
void	purified_from_heredoc(t_pipe **test_pipe, char *heredoc_dir);

#endif
