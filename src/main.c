/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:10 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/08 17:45:15 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data data;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error,\nnot needed arguments\n", 1);
		return (1);
	}
	init_data(&data);
	while (1)
	{
		signaux(&data);
		data.rl = readline(data.prompt);
		if (data.rl == NULL)
			break ;
		if (!ft_whitespace(data.rl))
			add_history(data.rl);
		verif_quote(data.rl);
		/*char yo[] = "ab | cdef | v";
		
		printf("strtok -> %s\n", strtok(yo, "|"));
		// printf("yo = %s\n", yo);
		printf("strtok -> %s\n", strtok(NULL, "|"));
		// printf("yo = %s\n", yo);
		*/
		printf("%s\n", data.rl);
	}
	return (0);
}
