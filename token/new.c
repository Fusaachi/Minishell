/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fusaaki <fusaaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:02:19 by fusaaki           #+#    #+#             */
/*   Updated: 2025/02/14 16:02:28 by fusaaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*new_token(const char *src, size_t size)
{
	t_token	*new;

	new = malloc(sizeof(*new));
	new->content = malloc(sizeof(char) * size + 1);
	ft_strlcpy(new->content, src, size);
	if (!new->content && !new)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->type = 0;
	return (new);
}

t_cmd	*new_cmd(const char *src, size_t size)
{
	t_cmd	*new;

	new = malloc(sizeof(*new));
	new->content = malloc(sizeof(char) * size + 1);
	ft_strlcpy(new->content, src, size);
	if (!new->content && !new)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->t_first = NULL;
	new->token = NULL;
	split_token(new, new->content);
	return (new);
}
