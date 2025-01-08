/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:13:44 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/08 17:14:20 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_signal(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n$>");
		//rl_on_new_line();
	}
}

void	signaux(t_data *data)
{
	struct sigaction sa;
	struct sigaction sa1;

	sa.sa_flags = 0;
	sa1.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigemptyset(&sa1.sa_mask);
	sa.sa_handler = handle_signal;
	sa1.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, NULL);
		//rl_replace_line(data->rl, 0);	

	sigaction(SIGQUIT, &sa1, NULL);
	data->rl = readline(data->prompt);
}