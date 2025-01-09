/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:36:13 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/09 13:53:04 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*init_env(t_env *env, t_data *data, char **envp)
{
	int	i;

	i = 1;
	env = lstnew(envp[0]);
	data->e_first = env;
	while (envp[i])
	{
		env->next = lstnew(envp[i]);
		env = env->next;
		i++;
	}
	return (data);
}

t_env	*lstnew(char *content)
{
	t_env	*new;

	new = malloc(sizeof(t_env *));
	new->content = ft_strdup(content);
	if (!new->content && !new)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	return (new);
}
