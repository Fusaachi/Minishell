/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 05:25:40 by pfranke           #+#    #+#             */
/*   Updated: 2024/08/09 13:59:43 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *s)
{
	int		len;
	int		i;
	char	buffer;

	i = 0;
	len = ft_strlen(s) - 1;
	while (i < (len + 1) / 2)
	{
		buffer = s[i];
		s[i] = s[len - i];
		s[len - i] = buffer;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	rep[12];
	int		minus;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		n = -n;
	}
	while (n > 0)
	{
		rep[i++] = (n % 10) + '0';
		n = n / 10;
	}
	rep[i] = '\0';
	ft_reverse(rep);
	if (minus)
		return (ft_strjoin("-", rep));
	return (ft_strdup(rep));
}
