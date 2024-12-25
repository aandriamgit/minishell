/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:49:46 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:27:47 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../utils.h"

static int	get_random_int(char *cmd, char *file)
{
	int		res;
	int		tmp;
	char	*random_char;

	tmp = ft_random_int(cmd);
	tmp = tmp + ft_random_int(file);
	random_char = malloc(tmp);
	res = (tmp % 101 + 101) % 101;
	res = res * (size_t)random_char % 101;
	free(random_char);
	random_char = NULL;
	return (res);
}

void	custom_permission_denied(char *file, char *str, t_vars *vars, int err)
{
	int	random_int;

	random_int = get_random_int(vars->t_pipe_a->cmd->cmd, file);
	(void)file;
	(void)str;
	if (random_int >= 0 && random_int <= 29)
		ft_putstr_fd_a("Access denied, nya-nyaa~ /ᐠ˵- ᴗ -˵マ\n", err);
	else if (random_int >= 30 && random_int <= 39)
		ft_putstr_fd_a("Nyaa~ You’re not catified to open this file ⊹₊ ⋆\n",
			err);
	else if (random_int >= 40 && random_int <= 49)
		ft_putstr_fd_a("Mew~ Paw-lease, you’re not on the VIP list ⋆˙⟡\n", err);
	else if (random_int >= 50 && random_int <= 59)
		ft_putstr_fd_a("This file says 'no touchy,' nya~ ⟡ ݁₊ .\n", err);
	else if (random_int >= 60 && random_int <= 69)
		ft_putstr_fd_a("Mew~ No access for you ⋆⭒˚.⋆\n", err);
	else if (random_int >= 70 && random_int <= 80)
		ft_putstr_fd_a("Permission denied, nya~ ⋆.˚\n", err);
	else
		ft_putstr_fd_a("Permission isn’t granted, nya~ ૮₍ ˶ᵔ ᵕ ᵔ˶ ₎ა\n", err);
}

void	custom_nosuchfileordir(char *file, char *str, t_vars *vars, int err)
{
	int	random_int;

	random_int = get_random_int(vars->t_pipe_a->cmd->cmd, file);
	(void)str;
	(void)vars;
	if (random_int >= 0 && random_int <= 29)
		ft_putstr_fd_a("No such file nya-nyaa~ /ᐠ˵- ᴗ -˵マ\n", err);
	else if (random_int >= 30 && random_int <= 39)
		ft_putstr_fd_a("Nyaa~ You’re not catified to find this file ⊹₊ ⋆\n",
			err);
	else if (random_int >= 40 && random_int <= 49)
		ft_putstr_fd_a("Mew~ you cant see it ? me neither ⋆˙⟡\n", err);
	else if (random_int >= 50 && random_int <= 59)
		ft_putstr_fd_a("This file says 'I'm not real' nya~ ⟡ ݁₊ .\n", err);
	else if (random_int >= 60 && random_int <= 69)
		ft_putstr_fd_a("Mew~ try again ⋆⭒˚.⋆\n", err);
	else if (random_int >= 70 && random_int <= 80)
		ft_putstr_fd_a("Did this file vanish into vogsphere, nya~? ⋆.˚\n", err);
	else
		ft_putstr_fd_a("No such file or directory, nya~ ૮₍ ˶ᵔ ᵕ ᵔ˶ ₎ა\n", err);
}

void	custom_is_a_dir(char *file, char *str, t_vars *vars, int err)
{
	int	random_int;

	random_int = get_random_int(vars->t_pipe_a->cmd->cmd, file);
	(void)str;
	(void)vars;
	if (random_int >= 0 && random_int <= 29)
		ft_putstr_fd_a("It's a directory, nya-nyaa~ /ᐠ˵- ᴗ -˵マ\n", err);
	else if (random_int >= 30 && random_int <= 39)
		ft_putstr_fd_a("Nyaa~ I'm pretty sure it's a directory ⊹₊ ⋆\n", err);
	else if (random_int >= 40 && random_int <= 49)
		ft_putstr_fd_a("That’s just a folder, nya~. ⋆˙⟡\n", err);
	else if (random_int >= 50 && random_int <= 59)
		ft_putstr_fd_a("Meeow~ A directory ? ew ⟡ ݁₊ .\n", err);
	else if (random_int >= 60 && random_int <= 69)
		ft_putstr_fd_a("Meeow~ It’s a directory, nya~! ⋆⭒˚.⋆\n", err);
	else if (random_int >= 70 && random_int <= 80)
		ft_putstr_fd_a("Nyaa~ Directories don’t do tricks, nya~. ⋆.˚\n", err);
	else
		ft_putstr_fd_a("That’s a directory, nya~nya~ ૮₍ ˶ᵔ ᵕ ᵔ˶ ₎ა\n", err);
}

void	custom_cmd_not_found(char *file, char *str, t_vars *vars, int err)
{
	int	random_int;

	random_int = get_random_int(vars->t_pipe_a->cmd->cmd, file);
	(void)str;
	(void)vars;
	if (random_int >= 0 && random_int <= 29)
		ft_putstr_fd_a("Command not found, nya-nyaa~ /ᐠ˵- ᴗ -˵マ\n", err);
	else if (random_int >= 30 && random_int <= 39)
		ft_putstr_fd_a("Command can't be found like a Ninja ⊹₊ ⋆\n", err);
	else if (random_int >= 40 && random_int <= 49)
		ft_putstr_fd_a("Meeow~ No such command ⋆˙⟡\n", err);
	else if (random_int >= 50 && random_int <= 59)
		ft_putstr_fd_a("Nyaa~ Not in my command dictionary ⟡ ݁₊ .\n", err);
	else if (random_int >= 60 && random_int <= 69)
		ft_putstr_fd_a("Mew~ Command went ~poof~ ⋆⭒˚.⋆\n", err);
	else if (random_int >= 70 && random_int <= 80)
		ft_putstr_fd_a("Try a different command, nya~ ⋆.˚\n", err);
	else
		ft_putstr_fd_a("That's not a command, nya~ ૮₍ ˶ᵔ ᵕ ᵔ˶ ₎ა\n", err);
}
