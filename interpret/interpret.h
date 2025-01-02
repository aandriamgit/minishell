/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:54:59 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/02 14:38:24 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_init/shell_init.h"
#include "../utils/utils.h"

void	exit_protocol(t_vars *vars, char **input, int nbr);
char	*nice_prompt(t_vars *vars);
void	ft_add_history(char *input, t_vars *vars);
void	uptade_input(char **input, t_vars *vars);
int		unclosed_quote(char **input, t_vars *vars);
void	free_vars(t_vars *vars);
int		unclosed_pipe(char **input, t_vars *vars);
void	extended_interpret(t_vars *vars, char **input);
void	extended_interpret_again(char **input, t_vars *vars, t_pipe **cmd);
int		error_redir(char *str, t_vars *t_var);
