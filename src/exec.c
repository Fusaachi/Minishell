/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:26:25 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/20 13:27:53 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	main_exec(t_data *data)
{
	if (pipe_pars(data->rl))
	{
		
	}
}

bool pipe_pars(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '|')
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (str[i] == '|' || !str[i])
			{
				ft_putstr_fd("MiniPaul: parse error near `|'\n", 2);
				return (false);
			}
		}
		i++;
	}
	return (true);
}