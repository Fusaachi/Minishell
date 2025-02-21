/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:10:02 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/21 14:12:10 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minishell.h"

typedef struct s_cmd_exec	t_cmd_exec;
typedef struct s_cmd		t_cmd;
typedef struct s_token		t_token;

int		len_str(char *str);
char	*epur_strcpy(char *src, char *dest, int lens, int i);
int		epur_len(char *str);
char	*epur(char *str);

t_env	*free_env(t_data *data, t_env *env);
void	all_free(t_data *data, t_env *env, char **envp);
void	free_cmd(t_cmd *cmd, t_data *data);
void	free_cmd_exec(t_cmd_exec *cmd_exec, t_data *data);

bool	is_char(char c);
bool	is_space(char c);
bool	is_quote(char c);
bool	is_empty(char *str);
bool	is_redir(char c);

int		skip_space(char *str);
int		skip_end(char *str);

#endif