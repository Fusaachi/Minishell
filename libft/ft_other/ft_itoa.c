/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:59:00 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/18 21:24:22 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_countnb(int n)
{
	size_t	count;
	long	temp;

	count = 0;
	temp = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		temp *= -1;
		count ++;
	}
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;
	long	temp;

	len = ft_countnb(n);
	i = len;
	temp = n;
	str = malloc((len * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
		temp *= -1;
	while (i >= 0)
	{
		str[i] = (temp % 10) + 48;
		temp /= 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*int	main()
{
	printf("%s", ft_itoa(-4));
}*/