/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:05:47 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/29 10:09:28 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	if (c >= 33 && c <= 127)
		return (true);
	return (false);
}
