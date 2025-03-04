/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:08:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/04 16:40:03 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd_exec	*cmds_exec(t_data *data, t_cmd *cmd)
{
	t_cmd_exec	*cmd_exec;
	size_t		i;

	cmd = data->c_first;
	i = -1;
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
	return (data->cmd_first);
}

t_cmd_exec	*new_cmd_exec(t_cmd *cmd)
{
	t_cmd_exec	*new;
	size_t		len;
	size_t		i;

	i = 0;
	new = malloc(sizeof(*new));
	init_cmd_exec(new);
	cmd->token = cmd->t_first;
	while (cmd->token != NULL && cmd->token->type != CMD)
		cmd->token = cmd->token->next;
	if (cmd->token->type == CMD)
	{
		len = len_w_quote(cmd->token->content);
		new->cmd = malloc (sizeof(char *) * len + 1);
		strcpy_w_quote(new->cmd, cmd->token->content, len + 1);
		init_arg_exec(cmd, &cmd->token, new);
	}
	//else if (is_type(cmd->token))
	//	strcpy_w_quote(new->cmd, cmd->next->token->content, len + 1);
	new->next = NULL;
	return (new);
}

void	init_arg_exec(t_cmd *cmd, t_token **token, t_cmd_exec *cmd_exec)
{
	size_t	i;
	size_t	len;

	i = 1;
	cmd_exec->args = malloc(sizeof(char *) * (cmd->nb_arg + 2));
	cmd->token = *token;
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

void	init_cmd_exec(t_cmd_exec *cmd_exec)
{
	cmd_exec->args = NULL;
	cmd_exec->next = NULL;
	cmd_exec->type = CMD;
	cmd_exec->cmd = NULL;
	cmd_exec->redir = NULL;
}
