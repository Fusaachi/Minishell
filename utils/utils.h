/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:10:02 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/29 12:42:46 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minishell.h"

t_env	*free_env(t_data *data, t_env *env);
void	all_free(t_data *data, t_env *env, char **envp);

bool	is_char(char c);
bool	is_space(char c);
bool	is_quote(char c);
bool	is_empty(char *str);

int		skip_space(char *str);
int		skip_end(char *str);

#endif