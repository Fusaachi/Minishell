/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:30:57 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/11 20:51:01 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_env	t_env;

//utils

int					ft_srtprt(char **strs);
t_env				*lstlast(t_env *lst);

//echo

int					echo(char **argv);

//pwd

int					pwd(void);

//cd

int					cd(char *path);

//export

t_env				*export(t_env *env, char *content);

//env

int					bt_env(t_env *env);

//unset

t_env				*unset(char *name, t_env *env);

#endif // BUILTIN_H