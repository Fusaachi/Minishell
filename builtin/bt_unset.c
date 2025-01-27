/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:01:07 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/27 09:38:43 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	triple_free(t_env *env)
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

t_env	*bt_unset(char *name, t_env *env)
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
