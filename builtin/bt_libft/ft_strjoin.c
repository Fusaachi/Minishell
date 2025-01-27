/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:02:39 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/23 13:05:12 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rep;
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	rep = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!rep)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		rep[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		rep[i] = s2[i - len1];
		i++;
	}
	rep[i] = '\0';
	return (rep);
}
