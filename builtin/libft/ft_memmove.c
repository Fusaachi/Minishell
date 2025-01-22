/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:32:32 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/27 15:57:39 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*src;

	dst = (unsigned char *)destination;
	src = (const unsigned char *)source;
	if (dst < src)
	{
		i = 0;
		while (i++ < num)
			dst[i - 1] = src[i - 1];
	}
	else if (dst > src)
	{
		i = num;
		while (i-- != 0)
			dst[i] = src[i];
	}
	return (destination);
}
