/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:08:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/25 17:15:24 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd_exec	*init_cmd_exec(t_data *data, t_cmd *cmd)
{
	t_cmd_exec	*cmd_exec;
	size_t		i;

	i = -1;
	cmd = data->c_first;
	while (++i < data->nb_cmd)
	{
		if (i == 0)
		{
			cmd_exec = new_cmd_exec(cmd);
			data->cmd_first = cmd_exec;
		}
		else
		{
			cmd_exec->next = new_cmd_exec(cmd);
			cmd_exec = cmd_exec->next;
		}
		cmd = cmd->next;
	}
	cmd = data->c_first;
	return (data->cmd_first);
}

t_cmd_exec	*new_cmd_exec(t_cmd *cmd)
{
	t_cmd_exec	*new;
	size_t		len;
	size_t		i;

	i = 0;
	new = malloc(sizeof(*new));
	cmd->token = cmd->t_first;
	len = len_w_quote(cmd->token->content);
	new->next = NULL;
	new->type = cmd->token->type;
	new->cmd = malloc (sizeof(char *) * len + 1);
	strcpy_w_quote(new->cmd, cmd->token->content, len + 1);
	init_arg_exec(cmd, new);
	return (new);
}

void	init_arg_exec(t_cmd *cmd, t_cmd_exec *cmd_exec)
{
	size_t	i;
	size_t	len;

	i = 1;
	cmd_exec->args = malloc(sizeof(char *) * (cmd->nb_arg + 2));
	len = len_w_quote(cmd->token->content);
	cmd_exec->args[0] = malloc(sizeof(char) * (len + 1));
	strcpy_w_quote(cmd_exec->args[0], cmd->token->content, len);
	if (cmd->token->next && cmd->token->next->type == ARG)
		cmd->token = cmd->token->next;
	while (i <= cmd->nb_arg && cmd->token->type == ARG)
	{
		len = len_w_quote(cmd->token->content);
		cmd_exec->args[i] = malloc(sizeof(char *) * len + 1);
		strcpy_w_quote(cmd_exec->args[i], cmd->token->content, len);
		cmd->token = cmd->token->next;
		i++;
	}
	cmd_exec->args[i] = NULL;
}
