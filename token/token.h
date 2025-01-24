/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:23:07 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/24 14:23:08 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../minishell.h"

typedef struct s_tok
{
	char	**strs;
	size_t	k;
	size_t	i;
	size_t	j;
	size_t	temp;
}t_tok;

char			*strtoken(char *str, const char *delimiter);
static size_t	ft_count_token( char *str, const char *delimit);
int				ft_isprint(int c);
bool			verif_delimit( char *str, const char *delimit, int i);
bool			is_print(char *str, int i);

#endif