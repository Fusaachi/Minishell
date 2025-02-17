/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:08:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/17 16:54:48 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_cmd_exec(t_cmd *cmd)
{
	t_cmd_exec	cmd_exec;
	size_t		len;

	cmd->token = cmd->t_first;
	len = len_w_quote(cmd->token->content);
	cmd_exec.cmd = malloc (sizeof(char *) * len + 1);
	strcpy_w_quote(cmd_exec.cmd, cmd->token->content, len + 1);
	printf("%s,\n", cmd_exec.cmd);
	cmd->token = cmd->token->next;
	init_arg_exec(cmd, &cmd_exec);
}
void	init_arg_exec(t_cmd *cmd, t_cmd_exec *cmd_exec)
{
	int	i;

	i = 0;

	cmd_exec->args = malloc(sizeof(char **) * cmd->nb_arg + 1);
	while (i < cmd->nb_arg)
	{
		
	}
	//cmd_exec->args = cmd->nb_arg;
	printf("nb d arg = %ld\n", cmd->nb_arg);
	//cmd->token = cmd->token->next;
	
}

