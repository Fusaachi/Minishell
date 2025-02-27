/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:17 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/27 13:21:46 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	type_token(t_cmd *cmd, t_data *data)
{
	bool	first;

	cmd = data->c_first;
	while (cmd)
	{
		cmd->token = cmd->t_first;
		first = true;
		while (cmd->token)
		{
			search_type(cmd, cmd->token, cmd->token->content, first);
			printf("TOKEN %s = %u\n", cmd->token->content, cmd->token->type);
			first = false;
			cmd->token = cmd->token->next;
		}
		cmd = cmd->next;
	}
}

void	search_type(t_cmd *cmd, t_token *token, char *str, bool first)
{
	if (first == 1)
		token->type = CMD;
	if (token->next && (token->type == OUTFILE || token->type == INFILE))
		token->next->type = CMD;
	if (strlen(str) <= 2 && str[0] == '<')
	{
		token->type = REDIR_IN;
		if (strlen(str) == 2 && str[1] == '<')
			token->type = HERE_DOC;
		if (token->next == NULL)
			return ;
		token->next->type = INFILE;
	}
	else if (strlen(str) <= 2 && str[0] == '>')
	{
		token->type = REDIR_OUT;
		if (strlen(str) == 2 && str[1] == '>')
			token->type = APPEND;
		if (token->next == NULL)
			return ;
		token->next->type = OUTFILE;
	}
	/*else if (strlen(str) == 2 && str[0] == '>' && str[1] == '>')
		token->type = APPEND;
	else if (strlen(str) == 2 && str[0] == '<' && str[1] == '<')
		token->type = HERE_DOC;*/
	if (token->type == ARG)
		cmd->nb_arg += 1;
}

bool	is_type(t_token *token)
{
	if (token->type == REDIR_IN || token->type == REDIR_OUT
		|| token->type == APPEND || token->type == HERE_DOC)
		return (true);
	return (false);
}

bool	same_type(t_cmd *cmd, t_data *data)
{
	cmd = data->c_first;
	while (cmd != NULL)
	{
		cmd->token = cmd->t_first;
		while (cmd->token != NULL)
		{
			printf("PRINT TYPE = %u\n", cmd->token->type);
			if (is_type(cmd->token) && cmd->token->next != NULL
				&& is_type(cmd->token->next))
			{
				printf("MiniPaul: parse error near `%s'\n",
					cmd->token->next->content);
				return (true);
			}
			if (is_type(cmd->token) && cmd->token->next == NULL)
			{
				printf("MiniPaul: parse error near `'\n");
				return (true);
			}
			cmd->token = cmd->token->next;
		}
		cmd = cmd->next;
	}
	return (false);
}
