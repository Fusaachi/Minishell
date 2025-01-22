/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:11:16 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/20 22:33:42 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, unsigned char c, size_t num)
{
	const unsigned char	*temp;

	temp = (const unsigned char *)src;
	while (num > 0)
	{
		if (*temp == c)
			return ((void *)temp);
		temp++;
		num--;
	}
	return ((void *)0);
}
