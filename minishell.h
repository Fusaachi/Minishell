/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fusaaki <fusaaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:32:53 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/10 17:21:38 by fusaaki          ###   ########.fr       */
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
	size_t		nb_cmd;
	char		*rl;
	const char	*prompt;
	int			fd[2];
}t_data;

void	handle_signal(int signum);

void	init(t_data *data, t_env *env, char **envp);
void	init_data(t_data *data);

bool	verif_quote(char *str);
bool	check_quote(char *str, size_t *i);

void	main_exec(t_data *data);
bool	pipe_pars(char *str);

#endif