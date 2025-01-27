/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:11:16 by pfranke           #+#    #+#             */
/*   Updated: 2024/06/02 18:52:47 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex2(char *hex, int i)
{
	int	j;

	j = i;
	if (j == 0)
	{
		ft_putchar('0');
		j = 1;
	}
	while (i > 0)
	{
		--i;
		ft_putchar(hex[i]);
	}
	return (j);
}

int	ft_puthex(unsigned int num, int type)
{
	char	*hex_digits;
	char	hex[16];
	int		i;

	i = 0;
	if (type == 0)
		hex_digits = "0123456789ABCDEF";
	else if (type == 1)
		hex_digits = "0123456789abcdef";
	while (num != 0)
	{
		hex[i++] = hex_digits[num % 16];
		num /= 16;
	}
	return (ft_puthex2(hex, i));
}
