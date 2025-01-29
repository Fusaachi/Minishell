/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:52:36 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/29 13:03:19 by pgiroux          ###   ########.fr       */
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

static size_t	ft_count_token( char *str, const char delimit)
{
	size_t i;
	size_t nb_tok;

	nb_tok = 1;
	i = 0;

	while (str[i])
	{
		if (is_quote(str[i]))
		{
			i++;
			while (!is_quote(str[i]))
				i++;
		}
		else if (str[i] == delimit)
			nb_tok++;
		i++;
	}
	return (nb_tok);
}
