/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:10:10 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/29 10:46:17 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "epur.h"

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i - 1 >= 0 && is_space(str[i - 1]))
		i--;
	return (i - 1);
}

char	*epur_strcpy(char *src, char *dest, int lens, int i)
{
	int		j;
	int		len;
	char	quote;

	i = skip_space(src);
	j = -1;
	len = skip_end(src);
	dest = malloc(sizeof(char *) * lens + 1);
	while (i <= len)
	{
		if (is_space(src[i]) || is_char(src[i]))
			dest[++j] = src[i];
		if (is_quote(src[i]))
		{
			quote = src[i];
			while (src[++i] != quote)
				dest[++j] = src[i];
			dest[++j] = src[i];
		}
		while (is_space(src[i]) && is_space(src[i + 1]))
			i++;
		i++;
	}
	dest[++j] = '\0';
	return (dest);
}

int	epur_len(char *str)
{
	int	i;
	int	j;
	int	len;
	int	switcher;

	switcher = -1;
	i = skip_space(str);
	j = 0;
	len = skip_end(str);
	while (i <= len && str[i++])
	{
		if (is_quote(str[i]))
			switcher = -switcher;
		if (switcher > 0)
			j++;
		if (is_space(str[i]) && switcher < 0)
		{
			j++;
			while (is_space(str[i++]))
				continue ;
		}
		if (!is_space(str[i]) && switcher < 0)
			j++;
	}
	return (j);
}

char	*epur(char *str)
{
	int		len;
	char	*new_str;

	new_str = NULL;
	len = epur_len(str);
	new_str = epur_strcpy(str, new_str, len, 0);
	return (new_str);
}
