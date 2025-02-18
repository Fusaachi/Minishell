/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:08:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/18 09:59:29 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_cmd_exec(t_cmd *cmd)
{
	t_cmd_exec	cmd_exec;
	size_t		len;
	size_t		i;

	i = 0;
	cmd->token = cmd->t_first;
	len = len_w_quote(cmd->token->content);
	cmd_exec.cmd = malloc (sizeof(char *) * len + 1);
	strcpy_w_quote(cmd_exec.cmd, cmd->token->content, len + 1);
	cmd->token = cmd->token->next;
	init_arg_exec(cmd, &cmd_exec);
	printf("cmd = %s,\n", cmd_exec.cmd);
	while(cmd_exec.args[i] != NULL)
	{
		printf("args[%zu] = %s,\n", i, cmd_exec.args[i]);
		i++;
	}
	
}
void	init_arg_exec(t_cmd *cmd, t_cmd_exec *cmd_exec)
{
	size_t i;
	size_t	len;

	i = 0;
	cmd_exec->args = malloc(sizeof(char **) * cmd->nb_arg + 1);
	while (i < cmd->nb_arg)
	{
		len = len_w_quote(cmd->token->content);
		cmd_exec->args[i] = malloc(sizeof(char *) * len + 1);
		strcpy_w_quote(cmd_exec->args[i], cmd->token->content, len);
		cmd->token = cmd->token->next;
		i++;
	}
	//cmd_exec->args = cmd->nb_arg;
	//cmd->token = cmd->token->next;
	
}

