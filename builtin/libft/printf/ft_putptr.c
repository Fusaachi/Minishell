/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:15:25 by pfranke           #+#    #+#             */
/*   Updated: 2024/06/19 14:10:10 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr2(char *buffer, int i)
{
	if (i == 0)
		buffer[i++] = '0';
	buffer[i++] = 'x';
	buffer[i++] = '0';
	while (i > 0)
		write(1, &buffer[--i], 1);
}

int	ft_putptr(void *ptr)
{
	char				*hex_digits;
	unsigned long long	value;
	char				buffer[16];
	int					i;

	i = 0;
	hex_digits = "0123456789abcdef";
	value = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	while (value != 0)
	{
		buffer[i++] = hex_digits[value % 16];
		value /= 16;
	}
	ft_putptr2(buffer, i);
	return (i + 2);
}
