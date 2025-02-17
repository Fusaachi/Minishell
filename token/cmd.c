/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:33:57 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/17 16:07:23 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_tok(t_data *data)
{
	t_cmd	*cmd;

	cmd = NULL;
	if (pipe_pars(data->rl))
	{
		split_cmd(data, data->rl, '|');
		if (!type_token(cmd, data))
			printf("MiniPaul: parse error near `\n'");
		else
		{
			cmd = data->c_first;
			init_cmd_exec(cmd);
		}
			
		free_cmd(cmd, data);
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
