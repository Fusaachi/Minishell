/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:53 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/06 16:53:45 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

enum	TYPE
{
	CMD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	APPEND,
}type;

typedef struct s_token
{
	type;
	char	*token;
	t_token	*next;
}t_token;

typedef struct s_shell
{
	t_token *first;
}t_shell;

int	ft_whitespace(char *str);
int	is_quote(char c);
int	verif_quote(char *str);
int	check_quote(char *str, int i);

#endif