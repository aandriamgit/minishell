/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:53:01 by mravelon          #+#    #+#             */
/*   Updated: 2024/10/17 17:02:54 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*nice_prompt_lol(void)
{
	char	*res;
	char	*tmp;
	char	buffer[1024];

	getcwd(buffer, 1024);
	tmp = ft_strjoin("\033[38;2;166;227;161m╭\033[38;2;148;226;213m ", buffer);
	res = ft_strjoin(tmp, "\033[38;2;137;180;250m  \033[0m");
	free(tmp);
	return (res);
}
