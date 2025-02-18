/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:27:38 by pfranke           #+#    #+#             */
/*   Updated: 2025/02/17 15:47:54 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Returns the value of the environment variable
 * 
 * @param str The environment variable
 * 
 * @return The value of the environment variable
 */
char	*find_env(t_env *env, char *key)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * @brief Returns the path of the command
 * 
 * @param data The data structure
 * 
 * @param cmd The command to find the path of
 * 
 * @return The path of the command, or NULL if the command is not found
 */
char	*where_path(t_data *data, char **cmd)
{
	char	**path;

	path = ft_split(find_env(data->e_first, "PATH"), ':');
}

int main(int argc, char **argv)
{
	t_data *data;
}
