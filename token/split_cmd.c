/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:52:36 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/07 13:57:42 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_strcmd(t_tok *t)
{
	t->tok = 0;
	t->i = 0;
	t->j = 0;
	t->quote = '\0';
}

static void	increment(size_t *i, size_t *j, char *str, const char delimiter)
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

t_cmd *split_cmd(t_data *data, char *str, const char delimiter)
{
	t_tok t;
	t_cmd *cmd;
	size_t i;
	
	i = -1;
	data->nb_cmd = ft_count_cmd(str, delimiter);
	init_strcmd(&t);
	while (++i < data->nb_cmd)
	{
		t.j = 0;
		if (str[t.i] == delimiter)
			t.i++;
		if (is_space(str[t.i]))
			t.i++;
		while (str[t.i] && str[t.i] != delimiter)
			increment(&t.i, &t.j, str, delimiter);
		if (i == 0)
			cmd = init_cmd(data, str, &t, i);
		else
		{
			cmd->next = init_cmd(data, str, &t, i);
			cmd = cmd->next;
		}
	}
	return (data->c_first);
}

size_t ft_count_cmd(char *str, const char delimit)
{
	size_t i;
	size_t nb_cmd;

	nb_cmd = 1;
	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			check_quote(str, &i);
		if (str[i] == delimit)
			nb_cmd++;
		if (str[i])
			i++;
	}
	return (nb_cmd);
}
t_cmd *new_cmd(const char *src, size_t size)
{
	t_cmd *new;

	new = malloc(sizeof(*new));
	new->content = malloc(sizeof(char) * size + 1);
	
	ft_strlcpy(new->content, src, size);
	if (!new->content && !new)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->token = NULL;
	new->t_first = NULL;
	return (new);
}
t_cmd *init_cmd(t_data *data, const char *src, t_tok *t, int j)
{
	t_cmd *cmd;

	if (src[t->i - 1] != ' ')
		cmd = new_cmd(&src[t->i - t->j], t->j + 1);
	else
		cmd = new_cmd(&src[t->i - t->j], t->j);
	if (j == 0)
		data->c_first = cmd;
	return(cmd);
}