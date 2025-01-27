/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:06:01 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/27 09:58:43 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**envmaker(t_env *e_first)
{
	t_env	*tmp;
	char	**env;
	int		i;

	i = 0;
	tmp = e_first;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = e_first;
	while (tmp)
	{
		env[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}

void	doubletabprintf(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_pathsplit(t_env *e_first, char *name)
{
	t_env	*tmp;

	tmp = e_first;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, name))
			return (ft_split(tmp->value, ':'));
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_getpath(t_env *e_first, char *name)
{
	char	**path;
	char	*tmp;
	int		i;

	path = ft_pathsplit(e_first, "PATH");
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp = ft_strjoin(tmp, name);
		if (!access(tmp, X_OK))
		{
			ft_free_tab(path);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	ft_free_tab(path);
	return (NULL);
}
