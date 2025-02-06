/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:17 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/06 15:07:24 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*init_token(t_token *token, t_cmd *cmd, t_data *data,  char **content)
{
	int	i;

	i = 1;
	
	token = new_token(token, content[0], 1);
	token->previous = NULL;
	cmd->t_first = token;
	printf("t_first = %p", cmd->t_first);
	printf( "type : %d\ncontenu : %s\n\n", token->type, token->content);
	while (content[i])
	{	
		token->next = new_token(token, content[i], 0);
		token = token->next;
		printf( "token %d\ntype : %i\ncontenu : %s\n\n", i, token->type, token->content);
		i++;
	}
	return (data);
}

t_token	*new_token(t_token *token, char *content, int first)
{
	t_token	*new;

	new = malloc(sizeof(*new));
	new->previous = token;
	search_type(new, content, first);
	new->content = ft_strdup(content);
	if (!new->content && !new)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	return (new);
}

t_token	*search_type(t_token *token, char *str, int first)
{
	if (str[0] == '-' || is_quote(str[0]))
		token->type = ARG;
	else if (strlen(str) == 1 && str[0] == '<')
		token->type = REDIR_IN;
	else if (first == 0 && token->previous != NULL && token->previous->type == REDIR_IN)
		token->type = INFILE;
	else if (strlen(str) == 1 && str[0] == '>')
		token->type = REDIR_OUT;
	else if (first == 0 && token->previous && token->previous->type == REDIR_OUT)
		token->type = OUTFILE;
	else if (strlen(str) == 2 && str[0] == '>' && str[1] == '>')
		token->type = APPEND;
	else if (strlen(str) == 2 && str[0] == '<' && str[1] == '<')
		token->type = HERE_DOC;
	else
		token->type = CMD;
	return (token);
}

