/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:11:50 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/11 22:25:45 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bt_env(t_env *env)
{
	t_env *tmp;

	if (!env)
		return (printf("Error: envp is NULL\n"));
	printf("content is %p\n", env);
	tmp = env;
	while (env)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
