/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:21:53 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/23 15:52:57 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		len;

	len = ft_strlen(str);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
	{
		free(ret);
		return (NULL);
	}
	ft_memcpy(ret, (void *)str, len);
	ret[len] = '\0';
	return (ret);
}
