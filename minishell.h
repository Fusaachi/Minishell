/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:53 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/18 14:15:48 by pgiroux          ###   ########.fr       */
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

typedef struct s_data
{
	t_env		*e_first;
	t_cmd		*c_first;
	t_cmd_exec	*cmd_first;
	size_t		nb_cmd;
	char		*rl;
	const char	*prompt;
	int			fd[2];
}	t_data;

typedef struct s_cmd_exec
{
	char		*cmd;
	char		**args;
	enum e_type	type;
	t_cmd_exec	*next;
}t_cmd_exec;

void		init(t_data *data, t_env *env, char **envp);
void		init_data(t_data *data);

bool		verif_quote(char *str);
bool		check_quote(char *str, size_t *i);
size_t		strcpy_w_quote(char *dest, const char *src, size_t size);
size_t		len_w_quote(char *str);

void		init_arg_exec(t_cmd *cmd, t_cmd_exec *cmd_exec);
t_cmd_exec	*init_cmd_exec(t_data *data, t_cmd *cmd);
t_cmd_exec	*new_cmd_exec(t_cmd *cmd);

void		main_exec(t_data *data);
bool		pipe_pars(char *str);

#endif