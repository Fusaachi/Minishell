/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:55:33 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/26 13:35:04 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rep;
	int		i;

	rep = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rep)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		rep[i] = f(i, s[i]);
		i++;
	}
	rep[i] = '\0';
	return (rep);
}
