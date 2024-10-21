/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:00:06 by aandriam          #+#    #+#             */
/*   Updated: 2024/10/21 14:39:42 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../first_test.h"

char	*get_file_dir(char *file)
{
	char	*res;
	char	*lol;

	lol = ft_strrchr(file, '/');
	if (!lol)
		return (NULL);
	lol++;
	res = ft_substr(file, 0, (ft_strlen(file) - ft_strlen(lol)));
	return (res);
}
