/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:01:07 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/11 22:25:05 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
char **unset(char *name, char **envp)
{
	char	**new_envp;
	int		i;
	int		j;

	if (name == NULL)
	{
		ft_srtprt(envp);
		return (envp);
	}
	i = 0;
	while (envp[i])
		i++;
	new_envp = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, ft_strlen(name)) != 0)
		{
			new_envp[j] = ft_strdup(envp[i]);
			j++;
		}
		i++;
	}
	new_envp[j] = NULL;
	envp = new_envp;
	return (envp);
}
*/

static void	triple_free (t_env *env)
{
	free(env->content);
	free(env->key);
	free(env->value);
	free(env);
}

t_env	*one_element(char *name, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (ft_strncmp(tmp->key, name, ft_strlen(name)) == 0)
	{
		env = env->next;
		triple_free(tmp);
		env = NULL;
		return (NULL);
	}
	return (env);
}

t_env	*unset(char *name, t_env *env)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = env;
	prev = env;
	printf("name = %p\n", env->next);
	if (!env->next)
	{
		return (one_element(name, env));
	}
	while (tmp)
	{
		if (ft_strncmp(tmp->key, name, ft_strlen(name)) == 0)
		{
			if (tmp == env)
			{
				env = env->next;
				free(tmp->content);
				free(tmp);
				return (env);
			}
			prev->next = tmp->next;
			triple_free(tmp);
			return (env);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (env);
}
