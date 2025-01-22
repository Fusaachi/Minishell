/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuntilnext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:01:15 by pfranke           #+#    #+#             */
/*   Updated: 2024/06/01 19:05:35 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printuntilnext(char *str, size_t *i)
{
	while (*str != '%' && *str)
	{
		write(1, str, 1);
		str++;
		(*i)++;
	}
	return (str);
}
