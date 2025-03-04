/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:33:57 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/04 18:10:36 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_tok(t_data *data)
{
	t_cmd		*cmd;
	t_cmd_exec	*cmd_exec;

	cmd = NULL;
	cmd_exec = NULL;
	if (pipe_pars(data->rl))
	{
		split_cmd(data, data->rl, '|');
		cmd = data->c_first;
		cmd->token = cmd->t_first;
		type_token(cmd, data);
		if (same_type(cmd, data))
			return ;
		cmd = data->c_first;
		init_cmd_exec(data, cmd);
		cmd_exec = data->cmd_first;
		while (cmd_exec != NULL)
		{
			/*while (i <= cmd->nb_arg)
			{
				printf("arg[%zu] = %s,\n", i, cmd_exec->args[i]);
				i++;
			}*/
			cmd = cmd->next;
			cmd_exec = cmd_exec->next;
		}
	}
	free_cmd(cmd, data);
}

void	print(t_data *data, t_cmd *cmd)
{
	int		i;
	int		j;

	i = 1;
	cmd = data->c_first;
	while (cmd != NULL)
	{
		cmd->token = cmd->t_first;
		j = 1;
		while (cmd->token != NULL)
		{
			cmd->token = cmd->token->next;
			j++;
		}
		cmd = cmd->next;
		i++;
	}
}
