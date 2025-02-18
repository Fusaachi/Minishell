/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:08:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/18 13:47:45 by pgiroux          ###   ########.fr       */
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
			cmd = cmd->next;
		}
		else
		{
			cmd_exec->next = new_cmd_exec(cmd);
			cmd_exec = cmd_exec->next;
			cmd = cmd->next;
		}
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
	cmd->token = cmd->t_first;
	len = len_w_quote(cmd->token->content);
	new->cmd = malloc (sizeof(char *) * len + 1);
	strcpy_w_quote(new->cmd, cmd->token->content, len + 1);
	cmd->token = cmd->token->next;
	init_arg_exec(cmd, new);
	return (new);
}

void	init_arg_exec(t_cmd *cmd, t_cmd_exec *cmd_exec)
{
	size_t	i;
	size_t	len;

	i = 0;
	cmd_exec->args = malloc(sizeof(char **) * cmd->nb_arg + 1);
	while (i < cmd->nb_arg)
	{
		len = len_w_quote(cmd->token->content);
		cmd_exec->args[i] = malloc(sizeof(char *) * len + 1);
		strcpy_w_quote(cmd_exec->args[i], cmd->token->content, len);
		//cmd_exec->args[i]->type = cmd->token->type;
		cmd->token = cmd->token->next;
		i++;
	}
}
