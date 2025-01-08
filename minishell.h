/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:53 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/08 16:40:14 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <bits/sigaction.h>

enum	e_type
{
	CMD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	APPEND,
};

typedef struct s_token	t_token;
struct s_token
{
	enum e_type	type;
	char		*token;
	t_token		*next;
};

typedef struct s_data
{
	t_token		*first;
	char		*rl;
	const char	*prompt;
}t_data;

void	signaux(t_data *data);
void	handle_signal(int signum);

void	init_data(t_data *data);

int		ft_whitespace(char *str);
int		is_quote(char c);
int		verif_quote(char *str);
int		check_quote(char *str, int i);

#endif