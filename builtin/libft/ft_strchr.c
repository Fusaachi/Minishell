/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:55:21 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/27 12:08:19 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (c == '\0')
		return ((char *)(str + ft_strlen(str)));
	while (*str != '\0' && *str != c % 256)
		str++;
	if (*str == c % 256)
		return ((char *)str);
	return (NULL);
}
