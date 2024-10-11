/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execution.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:42:11 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/11 14:46:50 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef SIMPLE_EXECUTION_H
# define SIMPLE_EXECUTION_H

t_pipe	*generate_redir(char *cmd, char *type, char *dir);

#endif
