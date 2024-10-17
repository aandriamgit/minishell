/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:37:58 by mravelon          #+#    #+#             */
/*   Updated: 2024/10/17 16:15:07 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../minishell.h"

void initiat(int **i, int **j, int **start, int **end)
{
	*i = 0;
	*j = 0;
	*start = 0;
	*end = 0;
}



int count_bloc(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
					i++;
		}
		while(str[i] == c && str[i])
			i++;
	}
	return (count);
}


char	**ft_split(char *str, char c)
{
	char **res;
	int i;
	int j;
	int start;

	i = 0;
	j = 0;
	start = 0;
	res = malloc(sizeof(char *) * (count_bloc(str, c) + 1));
	if (!res)
		return (NULL);
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c)
		{
			start = i;
			while (str[i] != c && str[i])
				i++;
			res[j] = ft_substr(str, start, i - 1);
			j++;
		}
		while (str[i] == c && str[i])
			i++;
	}
	res[j] = NULL;
	return (res);
}


/*int	main(int argc, char **argv)
{
	char **res;
	int i;

	i = 0;
	res = NULL;
	if(argc == 2)
	{
		res = ft_split(argv[1], ' ');
		while (res[i])
		{
			printf("res[%d] = %s\n", i, res[i]);
			i++;
		}
	}
	return (1);
}*/
