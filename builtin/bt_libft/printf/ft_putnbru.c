/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:58:01 by pfranke           #+#    #+#             */
/*   Updated: 2024/06/02 18:35:28 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int n)
{
	int	size;

	size = 0;
	if (n / 10 != 0)
		size += ft_putnbru(n / 10);
	ft_putchar('0' + (n % 10));
	size++;
	return (size);
}
