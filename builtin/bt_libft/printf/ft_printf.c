/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:12:57 by pfranke           #+#    #+#             */
/*   Updated: 2024/07/02 15:50:09 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse(char *str, va_list args, size_t *i)
{
	if (*str == 'i')
		*i += ft_putnbr(va_arg(args, int));
	else if (*str == 'd')
		*i += ft_putnbr(va_arg(args, int));
	else if (*str == 's')
		*i += ft_putstr(va_arg(args, char *));
	else if (*str == 'c')
		*i += ft_putchar(va_arg(args, int));
	else if (*str == 'u')
		*i += ft_putnbru(va_arg(args, unsigned int));
	else if (*str == 'x')
		*i += ft_puthex(va_arg(args, unsigned int), 1);
	else if (*str == 'X')
		*i += ft_puthex(va_arg(args, unsigned int), 0);
	else if (*str == 'p')
		*i += ft_putptr(va_arg(args, void *));
	else if (*str == '%')
		*i += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	char	*str;

	i = 0;
	va_start(args, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_parse(str, args, &i);
			str++;
		}
		else
			str = printuntilnext(str, &i);
	}
	va_end(args);
	return (i);
}
