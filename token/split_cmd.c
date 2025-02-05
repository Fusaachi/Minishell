/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:52:36 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/05 14:15:43 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_strcmd(t_tok *t, char *str, const char delimiter)
{
	t->strs = malloc(sizeof(char *) * (ft_count_cmd(str, delimiter) + 1));
	t->strs[ft_count_cmd(str, delimiter)] = NULL;
	if (!t->strs)
	{
		return ;
	}
	t->tok = 0;
	t->i = 0;
	t->j = 0;
	t->quote = '\0';
}

static void	jesaispas(size_t *i, size_t *j, char *str, const char delimiter)
{
	char	quote;

	if (is_quote(str[*i]))
	{
		quote = str[(*i)++];
		(*j)++;
		while (str[*i] && str[*i] != quote)
		{
			(*i)++;
			(*j)++;
		}
	}
	if (str[*i] && str[*i] != delimiter)
	{
		(*i)++;
		(*j)++;
	}
}

char	**split_cmd(char *str, const char delimiter)
{
	t_tok	t;

	init_strcmd(&t, str, delimiter);
	while (t.tok < ft_count_cmd(str, delimiter))
	{
		t.j = 0;
		if (str[t.i] == delimiter)
			t.i++;
		if (is_space(str[t.i]))
			t.i++;
		while (str[t.i] && str[t.i] != delimiter)
			jesaispas(&t.i, &t.j, str, delimiter);
		if (str[t.i - 1] != ' ')
		{
			t.strs[t.tok] = malloc(sizeof(char *) * t.j + 1);
			ft_strlcpy(t.strs[t.tok++], &str [t.i - t.j], t.j + 1);
		}
		else
		{
			t.strs[t.tok] = malloc(sizeof(char *) * t.j);
			ft_strlcpy(t.strs[t.tok++], &str[t.i - t.j], t.j);
		}
	}
	t.strs[t.tok] = NULL;
	return (t.strs);
}

size_t	ft_count_cmd( char *str, const char delimit)
{
	size_t	i;
	size_t	nb_tok;

	nb_tok = 1;
	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			check_quote(str, &i);
		if (str[i] == delimit)
			nb_tok++;
		if (str[i])
			i++;
	}
	return (nb_tok);
}
