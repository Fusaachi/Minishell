/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fusaaki <fusaaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:17 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/14 16:02:49 by fusaaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	type_token(t_cmd *cmd, t_data *data)
{
	bool	first;

	cmd = data->c_first;
	while (cmd)
	{
		cmd->token = cmd->t_first;
		first = true;
		while (cmd->token)
		{
			if (cmd->token->type == 0)
				search_type(cmd->token, cmd->token->content, first);
			if (is_type(cmd->token) && cmd->token->next == NULL)
				return (0);
			first = false;
			cmd->token = cmd->token->next;
		}
		cmd = cmd->next;
	}
	return (1);
}

void	search_type(t_token *token, char *str, bool first)
{
	if (first == 1)
		token->type = CMD;
	if (strlen(token->content) == 1 && str[0] == '<')
	{
		token->type = REDIR_IN;
		if (token->next == NULL)
			return ;
		token->next->type = INFILE;
	}
	else if (strlen(str) == 1 && str[0] == '>')
	{
		token->type = REDIR_OUT;
		if (token->next == NULL)
			return ;
		token->next->type = OUTFILE;
	}
	else if (strlen(str) == 2 && str[0] == '>' && str[1] == '>')
		token->type = APPEND;
	else if (strlen(str) == 2 && str[0] == '<' && str[1] == '<')
		token->type = HERE_DOC;
}

bool	is_type(t_token *token)
{
	if (token->type == 1 || token->type == 3
		|| token->type == 5 || token->type == 6)
		return (true);
	return (false);
}
