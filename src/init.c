/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:14:16 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/09 14:15:52 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_data(t_data *data)
{
	data->t_first = NULL;
	data->e_first = NULL;
	data->rl = NULL;
	data->prompt = "$>";
}

/*t_list	*initialistion(void)
{
	t_token	*token;

	token = malloc(sizeof(*token));
	if (token == 0)
	{
		free(token);
		exit(EXIT_FAILURE);
	}	
	token->token = "";
	token->next = NULL;
}*/
