/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dep.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:17 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:53:35 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEP_H
#define DEP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen_ap(const char *s);
char	*ft_strdup_ap(const char *s);
int		ft_strncmp_ap(const char *s1, const char *s2, size_t n);
char	*ft_substr_ap(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd_ap(char *s, int fd);
char	**ft_split_aa(char const *s, char c);

#endif
