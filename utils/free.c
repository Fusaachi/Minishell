/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:09:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/06 13:45:36 by pgiroux          ###   ########.fr       */
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
}


/*void	free_cmd(t_cmd *cmd, t_data *data)
{
	cmd = data->c_first;
	printf("c_first = %p\n", cmd);
	while(cmd->next != NULL)
	{
		cmd->token = cmd->t_first;
		while(cmd->token->next != NULL)
		{
			free(cmd->token->content);
			cmd->token = cmd->token->next;
		}
		free(cmd->token);
		free(cmd->content);
		cmd = cmd->next;
	}
	free(cmd);
}*/
void	free_tab(char **content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
}