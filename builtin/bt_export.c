/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:20:37 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/27 09:38:19 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*bt_export(t_env *env, char *content)
{
	t_env	*tmp;

	if (!env)
	{
		env = lstnew(content);
		if (!env)
			return (NULL);
		env->key = env_key(env->content);
		env->value = env_value(env->content);
		return (env);
	}
	tmp = lstlast(env);
	tmp->next = lstnew(content);
	tmp->next->key = env_key(content);
	tmp->next->value = env_value(content);
	return (env);
}
