/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:08:27 by pfranke           #+#    #+#             */
/*   Updated: 2024/07/02 15:51:52 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

char	*printuntilnext(char *str, size_t *i);

int		ft_printf(const char *format, ...);

int		ft_putnbr(int n);

int		ft_putstr(char *str);

int		ft_putchar(char c);

int		ft_puthex(unsigned int num, int type);

int		ft_putptr(void *ptr);

int		ft_putnbru(unsigned int n);
#endif