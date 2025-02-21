/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:14:16 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/21 10:12:53 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init(t_data *data, t_env *env, char **envp)
{
	init_data(data);
	if (envp[0] != NULL)
		init_env(env, data, envp);
}

void	init_data(t_data *data)
{
	data->c_first = NULL;
	data->e_first = NULL;
	data->rl = NULL;
	data->prompt = "MiniPaul>";
}
