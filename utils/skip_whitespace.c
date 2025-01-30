/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:45:25 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/30 13:07:42 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (i);
}

int	skip_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (is_space(str[i]))
		i--;
	return (i);
}
