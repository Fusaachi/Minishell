/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:21:13 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/28 14:42:47 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	tlen;
	char	*rep;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tlen = ft_strlen(s1);
	while (i < tlen && ft_isin(s1[i], set))
		i++;
	while (tlen > i && ft_isin(s1[tlen - 1], set))
		tlen--;
	rep = (char *)malloc((tlen - i + 1) * sizeof(char));
	if (!rep)
		return (NULL);
	while (i < tlen)
		rep[j++] = s1[i++];
	rep[j] = '\0';
	return (rep);
}
