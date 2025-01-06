/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyserlexical.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:42:18 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/06 10:33:40 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool is_space(char c)
{
    if ((c > 9 && c < 13) || c == 32)
        return (true);
    return (false);
}

bool    empty_line(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if(is_space(str[i]) == false)
            return (false);
		i++;
    }
    return (true);
}

static bool	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}

bool	skip_quote_iter_incr(char *raw,
			size_t *iter)
{
	char	c;

	c = raw[*iter];
	(*iter)++;
	while (raw[*iter] && raw[*iter] != c)
		(*iter)++;
	if (raw[*iter] == c)
		return (true);
	return (false);
}

bool	verif_quote(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]) == true)
		{
			if (skip_quote_iter_incr(str, &i) == false)
			{
				ft_putendl_fd("Error: Unclosed Quote", 2);
				return (false);
			}
		}
		if (str[i])
			i++;
	}
	return (true);
}