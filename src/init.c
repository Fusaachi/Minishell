/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:14:16 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/07 16:53:07 by pgiroux          ###   ########.fr       */
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
	data->cmd_first = NULL;
	data->rl = NULL;
	data->prompt = "MiniPaul>";
}

void	init_cmd_exec(t_cmd_exec *cmd_exec)
{
	cmd_exec->args = NULL;
	cmd_exec->first = true;
	cmd_exec->next = NULL;
	cmd_exec->type = ARG;
	cmd_exec->cmd = NULL;
	cmd_exec->redir = NULL;
	cmd_exec->redir_first = NULL;
}
