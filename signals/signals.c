/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fusaaki <fusaaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:13:44 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/14 11:13:35 by fusaaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handle_sigint(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signals(void)
{
	struct sigaction	sa;
	struct sigaction	sa1;

	sa.sa_flags = 0;
	sa1.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigemptyset(&sa1.sa_mask);
	sa.sa_handler = handle_sigint;
	sa1.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa1, NULL);
}
