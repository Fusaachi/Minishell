/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:42:18 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/18 21:25:36 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	verif_quote(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
		{
			if (!check_quote(str, &i))
			{
				ft_putstr_fd("Error,\nQuote no closed\n", 2);
				return (false);
			}
			i++;
		}
		else if (str[i])
			i++;
	}
	return (true);
}

bool	check_quote(char *str, size_t *i)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != quote)
		(*i)++;
	if (str[*i] == '\0')
		return (false);
	return (true);
}

size_t	strcpy_w_quote(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	quote;

	j = 0;
	i = -1;
	if (size == 0)
		return (ft_strlen(src));
	while (src[++i] != '\0')
	{
		if (is_quote(src[i]))
		{
			quote = src[i];
			i++;
			while (src[i] != quote)
			{
				dest[j++] = src[i];
				i++;
			}
		}
		else
			dest[j++] = src[i];
	}
	dest[j++] = '\0';
	return (ft_strlen(src));
}

size_t	len_w_quote(char *str)
{
	size_t	i;
	size_t	len;
	char	quote;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
		{
			quote = str[i];
			i++;
			while (str[i] != quote)
			{
				i++;
				len++;
			}
		}
		else
			len++;
		i++;
	}
	return (len);
}
