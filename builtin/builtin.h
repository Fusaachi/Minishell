/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:30:57 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/27 09:40:24 by pfranke          ###   ########.fr       */
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

/**
 * You know what echo does. It prints stuff.
 * 
 * @todo Change it to void... No point in using int.
 */
int					bt_echo(char **argv);

//pwd

/**
 * @brief Prints the current working directory to the standard output.
 * 
 * This function retrieves the current working directory and prints it
 * to the standard output.
 * 
 * @return Always returns 0.
 * 
 * @todo Change it to void... No point in using int.
 */
int					bt_pwd(void);

//cd
/**
 * Changes the current working directory.
 *
 * @param path The path to the new working directory.
 * @return 0 on success, -1 on failure.
 */
int					bt_cd(char *path);

//export

/**
 * Adds a new environment variable to the list.
 *
 * @param env The current environment list.
 * @param content The content of the new environment variable.
 * @return The updated environment list.
 */
t_env				*bt_export(t_env *env, char *content);

//env

/**
 * Prints the environment variables to the standard output.
 *
 * @param env The environment list.
 * @return 0 on success, -1 on failure.
 */
int					bt_env(t_env *env);

//unset

/**
 * Removes an environment variable from the list.
 *
 * @param name The name of the environment variable to remove.
 * @param env The environment list.
 * @return The updated environment list.
 * 
 * @todo It uses too many lines. Try to simplify it.
 */
t_env				*bt_unset(char *name, t_env *env);

#endif // BUILTIN_H