/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fusaaki <fusaaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:52:36 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/14 16:22:15 by fusaaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_c(t_c *c)
{
	c->tok = 0;
	c->i = 0;
	c->j = 0;
	c->quote = '\0';
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

t_cmd	*split_cmd(t_data *data, char *str, const char delimiter)
{
	size_t	i;
	t_cmd	*cmd;
	t_c		c;

	i = -1;
	data->nb_cmd = ft_count_cmd(str, delimiter);
	init_c(&c);
	while (++i < data->nb_cmd)
	{
		c.j = 0;
		if (str[c.i] == delimiter)
			c.i++;
		if (is_space(str[c.i]))
			c.i++;
		while (str[c.i] && str[c.i] != delimiter)
			increment(&c.i, &c.j, str, delimiter);
		if (i == 0)
			cmd = init_cmd(data, str, &c, i);
		else
		{
			cmd->next = init_cmd(data, str, &c, i);
			cmd = cmd->next;
		}
	}
	return (data->c_first);
}

size_t	ft_count_cmd(char *str, const char delimit)
{
	size_t	i;
	size_t	nb_cmd;

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

t_cmd	*init_cmd(t_data *data, const char *src, t_c *c, int j)
{
	t_cmd	*cmd;

	if (src[c->i - 1] != ' ')
		cmd = new_cmd(&src[c->i - c->j], c->j + 1);
	else
		cmd = new_cmd(&src[c->i - c->j], c->j);
	if (j == 0)
		data->c_first = cmd;
	return (cmd);
}
