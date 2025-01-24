/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:53 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/24 14:31:53 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "signals/signals.h"
# include "env/env.h"
# include <stdbool.h>
# include "utils/utils.h"
# include "token/token.h"

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
	t_token		*t_first;
	t_env		*e_first;
	char		*rl;
	const char	*prompt;
}t_data;

void	handle_signal(int signum);

void	init(t_data *data, t_env *env, char **envp);
void	init_data(t_data *data);

char	*strtoken(char *str, const char *delimiter);

bool	ft_whitespace(char *str);
bool	is_quote(char c);
bool	verif_quote(char *str);
int		check_quote(char *str, int i);

void	main_exec(t_data *data);
bool	pipe_pars(char *str);

#endif