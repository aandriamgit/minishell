/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dep.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:17 by aandriam          #+#    #+#             */
/*   Updated: 2024/12/27 14:06:23 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEP_H
# define DEP_H

# include "../../../minishell.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen_ap(const char *s);
char	*ft_strdup_ap(const char *s);
int		ft_strncmp_ap(const char *s1, const char *s2, size_t n);
char	*ft_substr_ap(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd_ap(char *s, int fd);
char	**ft_split_aa(char const *s, char c);
void	expend(char **str, t_list *env, t_vars *vars);
char	*gen_exit_code(t_vars *vars);
char	*get_the_thing(char *tmp_str, int *j, t_vars *vars);

#endif
