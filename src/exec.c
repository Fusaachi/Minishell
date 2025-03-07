/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:26:25 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/07 13:58:53 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	main_exec(t_data *data)
{
	(void)data;
}

bool	pipe_pars(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			check_quote(str, &i);
		if (str[i] == '|')
		{
			i++;
			while (is_space(str[i]) && str[i])
				i++;
			if (str[i] == '|' || !str[i] || str[0] == '|')
			{
				ft_putstr_fd("MiniPaul: parse error near `|'\n", 2);
				return (false);
			}
		}
		else if (str[i])
			i++;
	}
	return (true);
}
