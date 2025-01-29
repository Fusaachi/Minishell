/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:10 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/29 12:42:27 by pgiroux          ###   ########.fr       */
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
		ft_putstr_fd("Error,\nnot needed arguments\n", 2);
		return (1);
	}
	init(&data, &env, envp);
	while (1)
	{
		signals();
		data.rl = readline(data.prompt);
		if (data.rl == NULL)
			break ;
		if (!is_empty(data.rl))
			add_history(data.rl);
		if (verif_quote(data.rl))
		{
			data.rl = epur(data.rl);
			main_exec(&data);
			/*char yo[] = "ab | cdef | v";
			
			printf("strtok -> %s\n", strtok(yo, "|"));
			// printf("yo = %s\n", yo);
			printf("strtok -> %s\n", strtok(NULL, "|"));
			// printf("yo = %s\n", yo);
			*/
			printf("%s\n", data.rl);
			free(data.rl);
		}
	}
	all_free(&data, &env, envp);
	return (0);
}
