/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_interpret.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:31:02 by aandriam          #+#    #+#             */
/*   Updated: 2025/01/06 11:33:17 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "interpret.h"

void	extended_interpret_again(char **input, t_vars *vars, t_pipe **cmd)
{
	check_input(input);
	formating(input, vars->env, vars);
	if (unclosed_quote(input, vars) || unclosed_pipe(input, vars)
		|| error_redir(*input, vars, 0))
		extended_interpret(vars, input);
	else
	{
		*cmd = gen_pipe(input);
		vars->cmd = *cmd;
	}
}

void	extended_interpret(t_vars *vars, char **input)
{
	show_errors(vars);
	if (vars->input)
	{
		free(vars->input);
		vars->input = NULL;
	}
	if (*input != NULL)
	{
		free(*input);
		*input = NULL;
	}
}
