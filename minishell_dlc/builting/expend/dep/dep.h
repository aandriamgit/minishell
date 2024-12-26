/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dep.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:17 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/25 20:28:51 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEP_H
# define DEP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen_a(const char *s);
char	*ft_strdup_a(const char *s);
int		ft_strncmp_a(const char *s1, const char *s2, size_t n);
char	*ft_substr_a(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);

#endif
