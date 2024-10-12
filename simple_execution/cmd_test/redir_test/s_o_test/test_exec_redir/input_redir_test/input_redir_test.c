/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redir_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:14:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/12 16:47:51 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../simple_execution.h"

int	file_exist(char *dir)
{
	if (access(dir, F_OK) == 0)
		return (1);
	return (0);
}
