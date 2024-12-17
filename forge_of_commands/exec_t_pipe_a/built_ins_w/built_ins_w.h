/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins_w.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:18:03 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/16 12:10:48 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_t_pipe_a.h"

void	built_ins_w(t_command_a *cmd, t_vars *vars);
void	ft_echo_w(t_command_a *cmd, t_vars *vars);
void	ft_cd_w(t_command_a *cmd, t_vars *vars);
void	ft_pwd_w(t_command_a *cmd, t_vars *vars);
void	ft_unset_w(t_command_a *cmd, t_vars *vars);
void	ft_env_w(t_command_a *cmd, t_vars *vars);
void	ft_export_w(t_command_a *cmd, t_vars *vars);
