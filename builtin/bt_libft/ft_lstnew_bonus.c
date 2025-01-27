/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:31:27 by pfranke           #+#    #+#             */
/*   Updated: 2024/05/26 13:35:33 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rep;

	rep = malloc(sizeof(t_list));
	if (!rep)
		return (NULL);
	rep->content = content;
	rep->next = NULL;
	return (rep);
}
