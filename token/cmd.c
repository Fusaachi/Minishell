/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:33:57 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/05 17:05:00 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void cmd_tok(t_data *data, t_cmd *cmd)
{
	if (pipe_pars(data->rl))
	{
		init_cmd(cmd, data, split_cmd(data->rl, '|'));
		cmd = data->c_first;
		cmd->token = cmd->t_first;
	}
}

t_cmd	*new_cmd(char *content)
{
	t_cmd	*new;

	new = malloc(sizeof(*new));
	new->content = ft_strdup(content);
	if (!new->content && !new)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	return (new);
}

t_data	*init_cmd(t_cmd *cmd, t_data *data, char **content)
{
	t_token	token;
	int		i;

	i = 1;
	cmd = new_cmd(content[0]);
	printf("commande 0, contenu : %s\n", cmd->content);
	init_token(&token, data, split_cmd(cmd->content, ' '));
	cmd->t_first = cmd->token;
	data->c_first = cmd;
	while (content[i])
	{
		cmd->next = new_cmd(content[i]);
		init_token(&token, data, split_cmd(cmd->next->content, ' '));
		cmd->next->t_first = cmd->next->token;
		cmd = cmd->next;
		printf( "commande %d, contenu : %s\n",i , cmd->content);
		i++;
	}
	return (data);
}
