#include "../minishell.h"

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