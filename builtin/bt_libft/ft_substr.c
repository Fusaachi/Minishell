/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:39:21 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/27 15:51:26 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*rep;
	size_t		lrep;
	size_t		i;

	i = 0;
	lrep = ft_strlen(s) - start;
	if (len < lrep)
		lrep = len;
	if (start >= ft_strlen(s))
		lrep = 0;
	rep = malloc(sizeof(char) * lrep + 1);
	if (rep == NULL)
		return (NULL);
	while (i < lrep)
	{
		rep[i] = s[start];
		i++;
		start++;
	}
	rep[i] = '\0';
	return (rep);
}
