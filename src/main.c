/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:10 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/06 16:52:43 by pgiroux          ###   ########.fr       */
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
		ft_putstr_fd("Error,\nnot needed arguments\n", 1);
		return (1);
	}
	prompt = "$>";
	while (1)
	{
		rl = readline(prompt);
		if (rl == NULL)
			break ;
		if (!ft_whitespace(rl))
			add_history(rl);
		verif_quote(rl);
		/*char yo[] = "ab | cdef | v";
		
		printf("strtok -> %s\n", strtok(yo, "|"));
		// printf("yo = %s\n", yo);
		printf("strtok -> %s\n", strtok(NULL, "|"));
		// printf("yo = %s\n", yo);
		*/
		printf("%s\n", rl);
	}
	return (0);
}
