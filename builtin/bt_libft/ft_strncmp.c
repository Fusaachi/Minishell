/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:49:36 by pfranke           #+#    #+#             */
/*   Updated: 2025/02/19 16:20:58 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num && *str1 == *str2 && *str1 && *str2)
	{
		str1++;
		str2++;
		i++;
	}
	if (i >= num)
		return (0);
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

