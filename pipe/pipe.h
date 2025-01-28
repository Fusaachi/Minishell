/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:10:07 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/28 13:17:06 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "../minishell.h"
# include <sys/types.h>
# include <sys/wait.h>
/**
 * @brief Tranforms a list of environment variables into a double array.
 * 
 * This fonction converts the env list into a double array, usable by execve.
 * 
 * @param e_first Pointer to the first element of the environment list.
 * @return A new environment list.
 */
char	**envmaker(t_env *e_first);

/**
 * @brief Prints a double array of strings.
 * 
 * This function prints a double array of strings to the standard output.
 * 
 * @param tab The double array of strings to print.
 */
void	doubletabprintf(char **tab);

/**
 * @brief Retrieves the full path of a given executable name from
 *  the environment list.
 *
 * This function searches through the provided environment list to find the
 * full path of the executable specified by the `name` parameter.
 * 
 * If the executable is found, the function returns its full path as a string.
 * 
 * If the executable is not found, the function returns NULL.
 *
 * @param e_first Pointer to the first element of the environment list.
 * @param name The name of the executable to search for.
 * @return A string containing the full path of the executable if found,
 * or NULL if not found.
 */
char	*ft_getpath(t_env *e_first, char *name);

/**
 * @brief Executes a command with the provided arguments and environment.
 * 
 * This function executes the command specified by the `command` parameter
 * with the provided arguments and environment.
 * 
 * @return Returns 0 on success, or 1 on fork failure.
 */
int		pipe_execone(char *command, char **args, t_env *e_first);

#endif