/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:09:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/10 15:25:53 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


t_env	*free_env(t_data *data, t_env *env)
{
	t_env	*tmpnext;

	env = data->e_first;
	while (env != NULL)
	{
		tmpnext = env->next;
		free(env->content);
		free(env->key);
		free(env->value);
		free(env);
		env = tmpnext;
	}
	return (NULL);
}

void	all_free(t_data *data, t_env *env, char **envp)
{
	if (envp[0] != NULL)
		free_env(data, env);
	//free(data->rl);
}