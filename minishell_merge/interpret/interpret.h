/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:54:59 by aandriam          #+#    #+#             */
/*   Updated: 2024/11/09 18:00:39 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_init/shell_init.h"
#include "formating/parsing.h"

void	exit_protocol(t_vars *vars, char **input);
char	*nice_prompt(void);
void	ft_add_history(char *input, t_vars *vars);
void	unclosed_quote(char **input);
