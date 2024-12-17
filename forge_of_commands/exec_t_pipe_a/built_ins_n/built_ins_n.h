/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins_n.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:02:14 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/04 08:25:59 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_t_pipe_a.h"

void	ft_echo_n(t_command_a *cmd, t_vars *vars);
void	ft_cd_n(t_command_a *cmd, t_vars *vars);
void	ft_pwd_n(t_command_a *cmd, t_vars *vars);
void	ft_unset_n(t_command_a *cmd, t_vars *vars);
void	ft_env_n(t_command_a *cmd, t_vars *vars);
void	ft_export_n(t_command_a *cmd, t_vars *vars);
void	ft_exit_n(t_command_a *cmd, t_vars *vars);
