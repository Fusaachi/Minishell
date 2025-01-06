/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:10 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/06 10:21:19 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv)
{
	const char	*prompt;
	char		*rl;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error,\nnot needed arguments", 1);
		return (1);
	}
	prompt = "$>";
	while (1)
	{
		rl = readline(prompt);
		if (rl == NULL)
			break;
		if (!ft_whitespace(rl))
			add_history(rl);
		verif_quote(rl);
		printf("%s\n", rl);
	}
	return (0);
}
