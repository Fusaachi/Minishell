/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:04:49 by fusaaki           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/18 21:25:54 by pfranke          ###   ########.fr       */
=======
/*   Updated: 2025/02/21 14:51:26 by pgiroux          ###   ########.fr       */
>>>>>>> Fusaaki
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
		if (is_quote(str[t.i]))
		{
			while (is_quote(str[t.i]))
			{
				if (check_quote(str, &t.i))
				{
					if (str[t.i])
						t.i++;
				}	
			}
		}
			//in_the_quote(str, &t);
		if (is_redir(str[t.i]))
		{
			split_token_redir(cmd, &str[t.start], t.i - t.start, t.first);
			for_the_redir(str, &t);
		}
		else if (!str[t.i] || is_space(str[t.i]) || str[t.i + 1] == '\0')
		{
			split_token_space(cmd, &str[t.start], t.i - t.start + 2, t.first);
			t.start = t.i + 1;
			t.first = false;
		}
		if (str[t.i])
			t.i++;
	}
}

void	in_the_quote(char *str, t_t *t)
{
	while (is_quote(str[t->i]))
	{
		if (check_quote(str, &t->i))
		{
			if (str[t->i])
				t->i++;
		}	
	}
}

void	for_the_redir(char *str, t_t *t)
{
	if (str[t->i] == str[t->i + 1])
		t->i++;
	t->start = t->i + 1;
	if (str[t->start] && is_space(str[t->start]))
	{
		t->i++;
		t->start++;
	}
	t->first = false;
}
