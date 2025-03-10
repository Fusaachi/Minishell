/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:43:55 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/10 14:15:52 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_arg(t_cmd *cmd, t_cmd_exec *new)
{
	size_t	len;

	new->type = CMD;
	len = len_w_quote(cmd->token->content);
	new->cmd = malloc (sizeof(char *) * len + 1);
	if (!new->cmd)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	strcpy_w_quote(new->cmd, cmd->token->content, len + 1);
	init_arg_exec(cmd, &cmd->token, new);
}

void	cmd_type_arg(t_cmd *cmd, t_cmd_exec *cmd_exec, size_t i, size_t len)
{
	len = len_w_quote(cmd->token->content);
	cmd_exec->args[i] = malloc(sizeof(char *) * len + 1);
	if (!cmd_exec->args[i])
		return (free(cmd_exec->args), exit(EXIT_FAILURE));
	strcpy_w_quote(cmd_exec->args[i], cmd->token->content, len);
}
