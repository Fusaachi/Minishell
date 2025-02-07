#include "../minishell.h"

void	split_token_redir(t_cmd *cmd, const char *str, size_t *i, size_t *start)
{
	char redir;
	size_t len;

	redir = str[*i];
	len = 1;
	if (str[*i + 1] == redir)
	{
		*i++;
		len = 2;
	}
	cmd->token = new_token(&str[start], len);
	*i++;
}



void	split_token_cmd(t_cmd *cmd, char *str, size_t *i, size_t *start)
{
	
}

void	split_token(t_cmd *cmd, char *str)
{
	t_tok t;
	size_t i;
	size_t start;

	i = 0;
	start = 0;
	init_strcmd(&t);
	while (str[i])
	{
		if (is_redir(str[i]))
			split_token_redir(cmd, str, )
		else
			//ft construct non redir
		//stock 
	}
}