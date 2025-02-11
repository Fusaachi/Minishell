/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fusaaki <fusaaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:33:57 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/11 16:05:08 by fusaaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void cmd_tok(t_data *data)
{
	t_cmd	*cmd;
	int i;
	int j;

	i = 1;
	cmd = NULL;
	if (pipe_pars(data->rl))
	{
		split_cmd(data, data->rl, '|');
		cmd = data->c_first;
		while (cmd != NULL)
		{
			printf("commande %i, content = %s,\n",i, cmd->content);
			cmd->token = cmd->t_first;
			j = 1;
			while(cmd->token != NULL)
			{
				printf("token %d, content = %s,\n", j, cmd->token->content);
				cmd->token =cmd->token->next;
				j++;
			}
			cmd = cmd->next;
			i++;
		}
	}
}

