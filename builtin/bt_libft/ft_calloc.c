/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:04:20 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/22 19:14:48 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*test;

	test = malloc(size * nbr);
	if (test == NULL)
	{
		free(test);
		return (NULL);
	}
	ft_bzero(test, nbr * size);
	return (test);
}
