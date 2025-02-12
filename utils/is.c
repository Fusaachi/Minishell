/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fusaaki <fusaaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:05:47 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/12 17:48:42 by fusaaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (false);
	}
	return (true);
}

bool	is_quote(char c)
{
	if (c == 39 || c == 34)
		return (true);
	return (false);
}

bool	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

bool	is_char(char c)
{
	if (c >= 33 && c <= 126)
		return (true);
	return (false);
}

bool	is_redir(char c)
{
	if (c == '>'|| c == '<')
		return (true);
	return (false);
}

bool	is_type(t_token *token)
{
	if (token->type == 1 || token->type == 3 || token->type == 5 || token->type == 6)
		return (true);
	return (false);
}
