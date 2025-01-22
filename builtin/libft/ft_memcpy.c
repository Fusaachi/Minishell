/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:32:32 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/27 11:50:45 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t	i;

	if (destination == source)
		return (destination);
	i = 0;
	while (i < num)
	{
		*((unsigned char *)(destination + i)) = *((unsigned char *)
				(source + i));
		i++;
	}
	return (destination);
}
