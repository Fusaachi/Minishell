/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:58:01 by pfranke           #+#    #+#             */
/*   Updated: 2024/06/01 19:46:10 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	size;
	int	sign;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	size = 0;
	sign = 1;
	if (n < 0)
	{
		ft_putchar('-');
		size = 1;
		n = -n;
	}
	if (n / 10 != 0)
		size += ft_putnbr(n / 10);
	ft_putchar('0' + (n % 10) * sign);
	size++;
	return (size);
}
