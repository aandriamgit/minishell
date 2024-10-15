/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:13:12 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/15 16:19:44 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lib/lib.h"

typedef struct s_command
{
	char					*cmd;
	char					**args;
}							t_command;

typedef struct s_redirection
{
	char					*type;

	struct s_command		*cmd;
	struct s_redirection	*next;
}							t_redirection;

typedef struct s_pipe
{
	struct s_redirection	*redirection;
	struct s_pipe			*next;
}							t_pipe;

typedef struct s_vars
{
	char					*log_dir;
	char					*history_dir;
	char					*input;
	char					**env;
	char					*env_dir;
	char					*env_dir_name;
	struct s_pipe			*pipe;
}							t_vars;

#endif
