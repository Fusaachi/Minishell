/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fusaaki <fusaaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:17 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/12 17:51:00 by fusaaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	type_token(t_cmd *cmd, t_data *data)
{
	cmd = data->c_first;
	while (cmd)
	{
		cmd->token = cmd->t_first;
		while (cmd->token)
		{
			if (cmd->token->type == 7)
				search_type(cmd->token, cmd->token->content);
			if (is_type(cmd->token) && cmd->token->next == NULL)
				return (0);
			cmd->token = cmd->token->next;
		}
		cmd = cmd->next;
	}
	return (1);
}

void	search_type(t_token *token, char *str)
{
	if (str[0] == '-' || is_quote(str[0]))
		token->type = ARG;
	else if (strlen(token->content) == 1 && str[0] == '<')
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
t_token *new_token(const char *src, size_t size)
{
	t_token *new;

	new = malloc(sizeof(*new));
	new->content = malloc(sizeof(char) * size + 1);
	ft_strlcpy(new->content, src, size);
	if (!new->content && !new)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->type = 7;
	return (new);
}




