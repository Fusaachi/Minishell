/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:08:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/05 16:35:42 by pgiroux          ###   ########.fr       */
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
			cmd_exec = new_cmd_exec(cmd, data);
			data->cmd_first = cmd_exec;
		}
		else
		{
			cmd_exec->next = new_cmd_exec(cmd, data);
			cmd_exec = cmd_exec->next;
		}
		cmd = cmd->next;
	}
	return (data->cmd_first);
}

t_cmd_exec	*new_cmd_exec(t_cmd *cmd, t_data *data)
{
	t_cmd_exec	*new;
	size_t		len;

	new = malloc(sizeof(*new));
	init_cmd_exec(new);
	cmd->token = cmd->t_first;
	while (cmd->token != NULL)
	{
		if (cmd->token->type == CMD)
		{
			len = len_w_quote(cmd->token->content);
			new->cmd = malloc (sizeof(char *) * len + 1);
			strcpy_w_quote(new->cmd, cmd->token->content, len + 1);
			init_arg_exec(cmd, &cmd->token, new);
		}
		if (is_type(cmd->token) && !new->redir)
			init_redir(cmd, &cmd->token, data);
		if (cmd->token != NULL)
			cmd->token = cmd->token->next;
	}
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
	while (i <= cmd->nb_arg)
	{
		if (cmd->token->type == ARG)
		{
			len = len_w_quote(cmd->token->content);
			cmd_exec->args[i] = malloc(sizeof(char *) * len + 1);
			strcpy_w_quote(cmd_exec->args[i], cmd->token->content, len);
			i++;
		}
		cmd->token = cmd->token->next;
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

t_redir	*init_redir(t_cmd *cmd, t_token **token, t_data *data)
{
	t_redir	*redir;
	bool	first;

	first = true;
	cmd->token = *token;

	while (cmd->token != NULL)
	{
		if (is_type(cmd->token) && first == true)
		{
			printf("REDIR = %u", cmd->token->type);
			redir = new_redir(cmd, &cmd->token);
			data->redir_first = redir;
			first = false;
		}
		else if (is_type(cmd->token) && first == false)
		{
			redir->next = new_redir(cmd, &cmd->token);
			redir = redir->next;
		}
		cmd->token = cmd->token->next;
	}
	return (data->redir_first);
}

t_redir	*new_redir(t_cmd *cmd, t_token **token)
{
	t_redir	*new;
	size_t	len;

	cmd->token = *token;
	new = malloc(sizeof(*new));
	new->type = cmd->token->type;
	cmd->token = cmd->token->next;
	len = len_w_quote(cmd->token->content);
	new->name = malloc(sizeof(char) * len + 1);
	strcpy_w_quote(new->name, cmd->token->content, len + 1);
	new->next = NULL;
	return (new);
}
