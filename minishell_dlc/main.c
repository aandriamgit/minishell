/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:35:55 by mravelon          #+#    #+#             */
/*   Updated: 2024/12/10 08:35:02 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	char *str;
	char **split;
	t_pipe *p;
	int i;
	int j;
	int k;
	t_list	*env_cp;
	t_list	*export;

	i = 0;
	j = 0;
	k = 0;
	(void)env;
	(void)argv;
	env_cp = NULL;
	split = NULL;
	str = NULL;
	export = NULL;
	p = NULL;
	if (argc == 1)
	{
		env_cp = duplicate_env(env);
		while (1)
		{
			str = readline("minishell >");
			if (!str)
				exit(0);
			add_history(str);
			check_input(&str);
			formating(&str, env_cp);
			p = gen_pipe(&str);
			while (p)
			{
				printf("\n\n\n");
				printf("pipe[%d]\n", i);
				while (p->redir)
				{
					printf("\n\n");
					printf("p[%d]->redir[%d]->type = %s\n", i, j, p->redir->type);
					printf("p[%d]->redir[%d]->file = %s\n", i, j, p->redir->file);
					j++;
					p->redir = p->redir->next;
				}
				j = 0;
					printf("\n");
					printf("p[%d]->cmd[%d] = %s\n", i, j, p->cmd->cmd);
					j++;
					printf("\n");
					while(p->cmd->arg[k])
					{
						printf("cmd[%d]->arg[%d] = %s\n", j, k, p->cmd->arg[k]);
						k++;
					}
					k = 0;
				j = 0;
				i++;
				p = p->next;
			}
			i = 0;
			printf("str_1 = %s\n", str);
		}
	}
	return (1);
}

/*int	main(int argc, char **argv, char **env)
{
	char *str;
	char **split;
	int i;
	int j;
	t_list	*env_cp;
	t_list	*export;

	i = 0;
	j = 0;
	(void)env;
	(void)argv;
	env_cp = NULL;
	split = NULL;
	str = NULL;
	export = NULL;
	if (argc == 1)
	{
		env_cp = duplicate_env(env);
		while (1)
		{
			str = readline("minishell >");
			add_history(str);
			check_input(&str);
			split = ft_split_na(str);
			check_expand(split, env_cp);
			free(str);
			str = ft_strjoin_p(&split);
			ft_putstr_p(str, 1);
			ft_putstr_p("$\n", 1);
			free (str);
		}
	}
	return (1);
}*/
