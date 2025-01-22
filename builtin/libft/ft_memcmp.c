/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:36:43 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/22 10:34:02 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = s1;
	t2 = s2;
	if (n != 0)
	{
		while (n > 0)
		{
			if (*t1++ != *t2++)
				return (*--t1 - *--t2);
			n--;
		}
	}
	return (0);
}
