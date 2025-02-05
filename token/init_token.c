/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:17 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/05 17:05:39 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*init_token(t_token *token, t_data *data, char **content)
{
	int	i;

	i = 1;
	token = new_token(token, content[0]);
	token->previous = NULL;
	while (content[i])
	{	
		printf( "token %d\ntype : %i\ncontenu : %s\n\n", i, token->type, token->content);
		token->next = new_token(token, content[i]);
		token = token->next;
		i++;
	}
	return (data);
}

t_token	*new_token(t_token *token, char *content)
{
	t_token	*new;

	new = malloc(sizeof(*new));
	new->previous = token;
	search_type(new, content);
	new->content = ft_strdup(content);
	if (!new->content && !new)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	return (new);
}

t_token	*search_type(t_token *token, char *str)
{
	if (str[0] == '-' || is_quote(str[0]))
		token->type = ARG;
	else if (strlen(str) == 1 && str[0] == '<')
		token->type = REDIR_IN;
	else if (token->previous && token->previous->type == REDIR_IN)
		token->type = INFILE;
	else if (strlen(str) == 1 && str[0] == '>')
		token->type = REDIR_OUT;
	else if (token->previous && token->previous->type == REDIR_OUT)
		token->type = OUTFILE;
	else if (strlen(str) == 2 && str[0] == '>' && str[1] == '>')
		token->type = APPEND;
	else if (strlen(str) == 2 && str[0] == '<' && str[1] == '<')
		token->type = HERE_DOC;
	else
		token->type = CMD;
	return (token);
}

/*void	is_CMD(t_token *token, char *content)
{
	int i;

	i = 0;
	while (content[i] && !is_space(content[i]))
		i++;
	token->cmd = malloc(sizeof(char *) * i + 1);
	ft_strlcpy(token->cmd, content, i);
}

void	is_arg(t_token *token, char *content)
{
	int i;

	i = 0;
	if (token->cmd != NULL)
	{
		while (content[i] && !is_space(content[i]))
			i++;
		i++;
	}
	token->argv = split_arg();
}*/

/*t_token	*init_tok(t_token *token, t_data *data, char **tokens)
{
	int	i;

	i = 1;
	token = newtoken(tokens[0]);
	data->t_first = token;
	token->type = ;
	token->cmd = NULL;
	if (token->type = CMD)
		is_CMD(token, tokens[i]);
	is_arg(token, tokens[i]);
	while (tokens[i])
	{
		token->next = lstnew(tokens[i]);
		token = token->next;
		token->type = ;
		token->cmd = NULL;
		if (token->type = CMD)
			is_CMD(token, tokens[i]);
		is_arg(token, tokens[i]);
		i++;
	}
	return (data);
}*/
