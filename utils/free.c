/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:09:59 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/07 16:36:05 by pgiroux          ###   ########.fr       */
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

void	free_cmd(t_cmd *cmd, t_data *data)
{
	t_token	*tmp;
	t_cmd	*c_tmp;

	cmd = data->c_first;
	while (cmd != NULL)
	{
		cmd->token = cmd->t_first;
		while (cmd->token != NULL)
		{
			tmp = cmd->token->next;
			free(cmd->token->content);
			free(cmd->token);
			cmd->token = tmp;
		}
		c_tmp = cmd->next;
		free(cmd->content);
		free(cmd);
		cmd = c_tmp;
	}
}

void	free_cmd_exec(t_cmd_exec *cmd, t_data *data)
{
	t_cmd_exec	*c_tmp;
	size_t		i;

	cmd = data->cmd_first;
	while (cmd != NULL)
	{
		cmd->redir = cmd->redir_first;
		if (cmd != NULL && cmd->type == CMD)
		{
			i = 0;
			while (cmd->args[i])
			{
				free(cmd->args[i]);
				i++;
			}
			free(cmd->args);
			free(cmd->cmd);
		}
		if (cmd != NULL && cmd->redir != NULL)
			free_redir(cmd);
		c_tmp = cmd->next;
		free(cmd);
		cmd = c_tmp;
	}
	data->cmd_first = NULL;
}

void	free_redir(t_cmd_exec *cmd)
{
	t_redir		*redir_tmp;

	cmd->redir = cmd->redir_first;
	while (cmd->redir != NULL)
	{
		redir_tmp = cmd->redir->next;
		free(cmd->redir->name);
		free(cmd->redir);
		cmd->redir = redir_tmp;
	}
}