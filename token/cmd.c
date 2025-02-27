/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:33:57 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/27 13:23:01 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_tok(t_data *data)
{
	t_cmd		*cmd;
	t_cmd_exec	*cmd_exec;
	size_t		i;

	i = 0;
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
		cmd->token = cmd->t_first;

		if (cmd->token->type == CMD)
		{
			init_cmd_exec(data, cmd);
			cmd_exec = data->cmd_first;
		}
		//if (is_type(cmd->token->type))
		//	init_redir_exec(data, cmd);
		while (cmd_exec != NULL)
		{
			printf("cmd = %s\ntype = %u\n", cmd_exec->cmd, cmd_exec->type);
			i = 0;
			while (cmd_exec->args[i])
			{
				printf("arg[%zu] = %s", i, cmd_exec->args[i]);
				i++;
			}
			cmd = cmd->next;
			cmd_exec = cmd_exec->next;
			printf("\n");
		}
		free_cmd(cmd, data);
		if (data->cmd_first != NULL)
			free_cmd_exec(cmd_exec, data);
	}
}

void	print(t_data *data, t_cmd *cmd)
{
	int		i;
	int		j;

	i = 1;
	cmd = data->c_first;
	while (cmd != NULL)
	{
		printf("commande %i, content = %s,\n", i, cmd->content);
		cmd->token = cmd->t_first;
		j = 1;
		while (cmd->token != NULL)
		{
			printf("token %d, content = %s, type = %d\n", j, cmd->token->content, cmd->token->type);
			cmd->token = cmd->token->next;
			j++;
		}
		cmd = cmd->next;
		i++;
	}
}
