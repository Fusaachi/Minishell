/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:10 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/21 10:13:02 by pgiroux          ###   ########.fr       */
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
		{
			add_history(data.rl);
			if (verif_quote(data.rl))
			{
				data.rl = epur(data.rl);
				cmd_tok(&data);
				main_exec(&data);
			}
		}
		free(data.rl);
	}
	rl_clear_history();
	all_free(&data, &env, envp);
	return (0);
}
