/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:04:49 by fusaaki           #+#    #+#             */
/*   Updated: 2025/02/18 17:23:44 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_token_redir(t_cmd *cmd, const char *str, size_t len, bool first)
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
	}
	split_token_space(cmd, &str[len], len_redir + 1, first);
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
		cmd->nb_arg += 1;
	}
}

void	split_token(t_cmd *cmd, char *str)
{
	t_t	t;

	t.i = 0;
	t.start = 0;
	t.first = true;
	while (str[t.i])
	{
		if (is_redir(str[t.i]))
		{
			split_token_redir(cmd, &str[t.start], t.i - t.start, t.first);
			if (str[t.i] == str[t.i + 1])
				t.i++;
			t.start = t.i + 1;
			if (is_space(str[t.start]))
				t.start++;
			t.first = false;
		}
		else if (is_space(str[t.i + 1]) || str[t.i + 1] == '\0')
		{
			split_token_space(cmd, &str[t.start], t.i - t.start + 2, t.first);
			t.start = t.i + 2;
			t.first = false;
		}
		t.i++;
	}
}
