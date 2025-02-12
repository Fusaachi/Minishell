#include "../minishell.h"

void	split_token_redir(t_cmd *cmd, const char *str, size_t len, bool  first)
{
	char	redir;
	int		i;
	int		len_redir;

	len_redir = 1;
	i = 0;
	redir = str[len];
	if (str[len + 1] == redir)
		len_redir = 2;
	if (!is_redir(str[i]))
	{
		split_token_space(cmd, str, len + 1, first);
		i = len;
		first = false;
	}
	split_token_space(cmd, &str[len], len_redir + 1, first);
	first = false;
}



void	split_token_space(t_cmd *cmd, const char *str, size_t len, bool first)
{
	if (first == true)
	{
		cmd->token = new_token(str, len);
		cmd->t_first = cmd->token;
	}
	else
	{
		cmd->token->next = new_token(str, len);
		cmd->token = cmd->token->next;
	}	
}
	

void	split_token(t_cmd *cmd, char *str)
{
	size_t	i;
	size_t	start;
	bool	first;

	i = 0;
	start = 0;
	first = true;
	while (str[i])
	{
		if (is_quote(str[i]))
			check_quote(str, &i);
		if (is_redir(str[i]))
		{
			split_token_redir(cmd, &str[start], i - start, first);
			if (str[i] == str[i + 1])
				i++;
			first = false;
			start = i + 1;
			if (is_space(str[start]))
				start++;
		}
		else if(is_space(str[i + 1]) || str[i + 1] == '\0')
		{
			split_token_space(cmd, &str[start], i - start + 2, first);
			first = false;
			start = i + 2;
		}
		i++;
	}
}
