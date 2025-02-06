/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:33:57 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/06 17:41:26 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void cmd_tok(t_data *data)
{
	t_cmd	*cmd;

	cmd = NULL;
	if (pipe_pars(data->rl))
	{
		split_cmd(data, data->rl, '|');
		cmd = data->c_first;
		//printf("%s\n", cmd->next->content);
		while (cmd != NULL)
		{
			printf("%s\n", cmd->content);
			cmd = cmd->next;
		}
	}
}



/*t_data	*init_cmd(t_cmd *cmd, t_data *data, char **content)
{
	t_token	token;
	int		i;

	i = 1;
	cmd = new_cmd(content[0]);
	printf("commande 0, contenu : %s\n", cmd->content);
	init_token(&token, cmd, data, split_cmd(cmd->content, ' '));
	printf("t_first cmd[0] = %p\n", cmd->t_first);
	data->c_first = cmd;
	while (content[i])
	{
		cmd->next = new_cmd(content[i]);
		init_token(&token, cmd, data, split_cmd(cmd->next->content, ' '));
		printf("t_first cmd [%i]= %p\n", i, cmd->t_first);
		cmd->next->t_first = cmd->next->token;
		cmd = cmd->next;
		printf( "commande %d, contenu : %s\n",i , cmd->content);
		i++;
	}
	return (data);
}*/
