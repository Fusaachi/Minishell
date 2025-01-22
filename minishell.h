/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:53 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/22 10:18:48 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "signals/signals.h"
# include "env/env.h"
# include "utils/utils.h"
# include "builtin/builtin.h"
# include "pipe/pipe.h"

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


void	init_data(t_data *data);

int		ft_whitespace(char *str);
int		is_quote(char c);
int		verif_quote(char *str);
int		check_quote(char *str, int i);

#endif