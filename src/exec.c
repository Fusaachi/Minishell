/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:26:25 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/30 17:41:10 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	main_exec(t_data *data)
{
	char	**result;

	if (pipe_pars(data->rl))
	{
		result = strtoken(data->rl, '|');
		/*
		char **result;
		int i = 0;
		int x = 0;
		while(result[i])
		{
			x = 0;
			while(result[i][x])
			{
				printf("str[%i][%d] = %c\n",i,x,result[i][x]);
				x++;
			}
			printf("\n");
			i++;
		}*/
	}
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
			if (str[i] == '|' || !str[i])
			{
				ft_putstr_fd("MiniPaul: parse error near `|'\n", 2);
				return (false);
			}
		}
		if (str[i])
			i++;
	}
	return (true);
}
