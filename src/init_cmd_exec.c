/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:08:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/03 15:22:41 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd_exec	*init_cmd_exec(t_data *data, t_cmd *cmd)
{
	t_cmd_exec	*cmd_exec;
	bool	i;

	i = true;
	cmd = data->c_first;
	cmd->token = cmd->t_first;
	printf("coucou");
	while (cmd != NULL)
	{
		printf("coucou");
		while (cmd->token != NULL)
		{
			if (i == true && (cmd->token->type == CMD || is_type(cmd->token)))
			{
				cmd_exec = new_cmd_exec(cmd, &cmd->token);
				data->cmd_first = cmd_exec;
				i = false;
			}
			else if (cmd->token->type == CMD || is_type(cmd->token)) 
			{
				cmd_exec->next = new_cmd_exec(cmd, &cmd->token);
				cmd_exec = cmd_exec->next;
			}
			cmd->token = cmd->token->next;
		}
		cmd = cmd->next;
	}
	cmd = data->c_first;
	return (data->cmd_first);
}

t_cmd_exec	*new_cmd_exec(t_cmd *cmd, t_token **token)
{
	t_cmd_exec	*new;
	size_t		len;
	size_t		i;

	i = 0;
	new = malloc(sizeof(*new));
	cmd->token = *token;
	len = len_w_quote(cmd->token->content);
	new->next = NULL;
	new->type = cmd->token->type;
	new->cmd = malloc (sizeof(char *) * len + 1);
	if (cmd->token->type == CMD)
	{
		strcpy_w_quote(new->cmd, cmd->token->content, len + 1);
		init_arg_exec(cmd, new);
	}
	else if (is_type(cmd->token))
		strcpy_w_quote(new->cmd, cmd->next->token->content, len + 1);
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
