/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:13:44 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/08 17:37:23 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_signal(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n$>");
		rl_replace_line("", 0);	
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
	sigaction(SIGQUIT, &sa1, NULL);
}
