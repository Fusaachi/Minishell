/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:14:16 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/06 16:42:16 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_shell *initialistion()
{
    t_shell *shell = malloc(sizeof(*shell));
    t_token *token = malloc(sizeof(*token));

    if (shell == NULL || token == 0)
        exit(EXIT_FAILURE);
    token->token;
    token->next = NULL;
    shell->first = token;
}