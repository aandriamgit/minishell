/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:33:28 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/05 16:43:56 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../redirection_test/redirection_test.h"
#include "../simple_execution.h"

t_pipe	*gen_pipe_test(t_command *cmd, t_pipe *prev, t_pipe *next);
void	add_pipe_next(t_pipe **first, t_pipe **second);
void	free_t_pipe_again(t_pipe **p_test);
int		init_test(t_pipe **p_test);
void	just_do_it(t_pipe *p_test, t_vars *vars);
void	add_input(t_pipe **p_test, char *input);
char	*get_err_dir(void);
void	finish_errors(char **tmp, char **res);
void	init_err(t_vars *vars);
void	add_input_w_redir(char *input, t_pipe **p_test);