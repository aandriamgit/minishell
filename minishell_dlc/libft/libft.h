/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:45:46 by mravelon          #+#    #+#             */
/*   Updated: 2024/11/29 17:41:59 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr_p(char *str, int fd);
void	ft_putnbr_p(int i, int fd);
void	ft_putchar_p(char c, int fd);
char	*ft_substr_p(int start, int end, char *str);
int	ft_strlen_p(char *str);
int ft_strcmp_p(char *first, char *second);
char	**ft_split_p(char const *s, char c);
char	*ft_strdup_p(char *str);
#endif
