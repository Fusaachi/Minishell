/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:10 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/22 14:55:13 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_env	env;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error,\nnot needed arguments\n", 1);
		return (1);
	}
	init_data(&data);
	if (envp[0] != NULL)
		init_env(&env, &data, envp);
	/*
	while (1)
	{
		signals();
		data.rl = readline(data.prompt);
		if (data.rl == NULL)
			break ;
		if (!ft_whitespace(data.rl))
			add_history(data.rl);
		verif_quote(data.rl);
		\*\/char yo[] = "ab | cdef | v";
		
		printf("strtok -> %s\n", strtok(yo, "|"));
		// printf("yo = %s\n", yo);
		printf("strtok -> %s\n", strtok(NULL, "|"));
		// printf("yo = %s\n", yo);
		\*\/
		printf("%s\n", data.rl);
	}
	*/
	printf("-----------------------------------------------------------------\n");
	bt_env(data.e_first);
	printf("efirst = %p\n", data.e_first);
	data.e_first = export(data.e_first, "yo=coucou");
	printf("-----------------------------------------------------------------\n");
	printf("efirst = %p\n", data.e_first);
	bt_env(data.e_first);
	printf("-----------------------------------------------------------------\n");
	data.e_first = unset("yo", data.e_first);
	printf("-----------------------------------------------------------------\n");
	printf("efirst = %p\n", data.e_first);
	bt_env(data.e_first);
	printf("-----------------------------------------------------------------\n");
	printf("Path is %s\n", ft_getpath(data.e_first, "lvm"));
	char **args = malloc(sizeof(char *) * 2);
	args[0] = ft_strdup("-l");
	args[1] = NULL;
	execone("ls", args, data.e_first);
	all_free(&data, &env, envp);
	return (0);
}
