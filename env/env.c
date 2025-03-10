/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:36:13 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/10 12:47:53 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*init_env(t_env *env, t_data *data, char **envp)
{
	int	i;

	i = 1;
	env = lstnew(envp[0]);
	data->e_first = env;
	env->key = env_key(env->content);
	env->value = env_value(env->content);
	while (envp[i])
	{
		env->next = lstnew(envp[i]);
		env = env->next;
		env->key = env_key(env->content);
		env->value = env_value(env->content);
		i++;
	}
	return (data);
}

t_env	*lstnew(char *content)
{
	t_env	*new;

	new = malloc(sizeof(*new));
	if (!new)
		exit(EXIT_FAILURE);
	new->content = ft_strdup(content);
	if (!new->content)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	return (new);
}

char	*env_key(char *str)
{
	int		len;
	int		i;
	char	*key;

	i = 0;
	len = 0;
	while (str[len] != '=')
		len++;
	key = malloc(sizeof(char *) * len + 1);
	if (!key)
		exit(EXIT_FAILURE);
	while (i < len)
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*env_value(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 1;
	while (str[i - 1] != '=')
		i++;
	if (str[i] == '\0')
		return (NULL);
	while (str[i + len])
		len++;
	return (ft_substr(str, i, len));
}
