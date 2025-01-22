/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:20:37 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/11 21:30:10 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*export(t_env *env, char *content)
{
	t_env	*tmp;

	if (!env)
	{
		env = lstnew(content);
		env->key = env_key(env->content);
		env->value = env_value(env->content);
		return (env);
	}
	tmp = lstlast(env);
	tmp->next = lstnew(content);
	tmp->next->key = env_key(content);
	tmp->next->value = env_value(content);

	printf("key = %s\nvalue = %s\n", tmp->next->key, tmp->next->value);
	printf("the one before :\nkey = %s\nvalue = %s\n", tmp->key, tmp->value);
	return (env);
}
/*
char **export(char *name, char **envp)
{
	char	**new_envp;
	int		i;

	if (name == NULL)
	{
		ft_srtprt(envp);
		return (envp);
	}
	i = 0;
	while (envp[i])
		i++;
	new_envp = ft_calloc(i + 2, sizeof(char *));
	i = 0;
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = ft_strdup(name);
	envp = new_envp;
	return (envp);
}
*/