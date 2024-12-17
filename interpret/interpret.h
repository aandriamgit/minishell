/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:54:59 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:34:57 by aandriam         ###   ########.fr       */
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
