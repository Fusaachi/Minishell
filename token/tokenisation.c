/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:52:36 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/24 14:31:39 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**strtoken(char *str, const char *delimiter)
{
	t_tok	*t;

	t->k = 0;
	t->i = 0;
	t->j = 0;
	t->strs = malloc((ft_count_token(str, delimiter) + 1) * sizeof(char *));
	if (!t->strs)
		return (NULL);
	while (t->k < ft_count_token(str, delimiter))
	{
		if (verif_delimit(str, delimiter, t->i))
			t->i += ft_strlen(delimiter);
		while (str[t->i] == 32)
			t->i++;
		t->j = t->i;
		while (str[t->i] && !verif_delimit(str, delimiter, t->i))
			t->i++;
		t->temp = t->i;
		while (str[t->temp -1] == 32)
			t->temp--;
		t->strs[t->k] = malloc ((t->temp - t->j) * sizeof(char));
		ft_strlcpy(t->strs[t->k++], str + t->j, t->temp - t->j + 1);
	}
	t->strs[t->k] = NULL;
	return (t->strs);
}

static size_t	ft_count_token( char *str, const char *delimit)
{
	size_t	i;
	size_t	s_del;
	size_t	nb_tok;

	i = 0;
	s_del = strlen(delimit);
	nb_tok = 0;
	if (is_char(str, i))
	{
		nb_tok = 1;
		while (str[i])
		{
			if (str[i] == delimit[0])
			{
				if (verif_delimit(str, delimit, i)
					&& is_char(str, i + s_del) && str[i + s_del])
				{
					nb_tok++;
					i += s_del;
				}
			}
			i++;
		}
	}
	return (nb_tok);
}

bool	verif_delimit( char *str, const char *delimit, int i)
{
	int	j;

	j = 0;
	while (str[i] == delimit[j] && delimit[j])
	{
		i++;
		j++;
	}
	if (delimit[j] == '\0')
		return (true);
	return (false);
}

bool	is_print(char *str, int i)
{
	while (str[i] == 32 && str[i])
		i++;
	if (str[i] >= 33 && str[i] <= 127)
		return (true);
	return (false);
}
