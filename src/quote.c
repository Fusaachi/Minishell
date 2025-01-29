/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:42:18 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/29 10:47:23 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_whitespace(char *str)
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

bool	verif_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
		{
			if (!check_quote(str, i))
			{
				ft_putstr_fd("Error,\nQuote no closed\n", 2);
				return (false);
			}
			else
				i = check_quote(str, i);
		}
		i++;
	}
	return (true);
}

int	check_quote(char *str, int i)
{
	char	quote;

	quote = str[i];
	i++;
	while (str[i] && str[i] != quote)
		i++;
	if (str[i] == quote)
		return (i);
	return (0);
}

int	check_quote2(char *str, int i)
{
	char	quote;
	int		other;

	quote = str[i];
	i++;
	other = 1;
	while (str[i] && str[i] != quote)
	{
		i++;
		other++;
	}
	if (str[i] == quote)
		return (other);
	return (0);
}
