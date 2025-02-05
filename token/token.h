/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:23:07 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/30 14:43:33 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../minishell.h"

typedef struct s_tok
{
	char	**strs;
	char	quote;
	size_t	tok;
	size_t	i;
	size_t	j;
}t_tok;

void	init_strtok(t_tok *t, char *str, const char delimiter);
size_t	ft_count_token( char *str, const char delimit);
char	**strtoken(char *str, const char delimiter);

#endif