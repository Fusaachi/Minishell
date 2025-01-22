/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:08:21 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/11 20:20:40 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Sorts by ASCII order and prints the strings sorted

#include "../minishell.h"

//Copies a double array of strings, and mallocs it

char	**ft_memdcpy(char **dst, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

void	ft_dfree(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_srtprt(char **strs)
{
	int		i;
	int		j;
	char	*tmp;
	char	**strs_cpy;

	i = 0;
	while (strs[i])
		i++;
	strs_cpy = ft_calloc(i + 1, sizeof(char *));
	strs_cpy = ft_memdcpy(strs_cpy, strs);
	i = 0;
	while (strs_cpy[i])
	{
		j = i + 1;
		while (strs_cpy[j])
		{
			if (ft_strcmp(strs_cpy[i], strs_cpy[j]) > 0)
			{
				tmp = strs_cpy[i];
				strs_cpy[i] = strs_cpy[j];
				strs_cpy[j] = tmp;
			}
			j++;
		}
		printf("%s\n", strs_cpy[i]);
		i++;
	}
	ft_dfree(strs_cpy);
	return (EXIT_SUCCESS);
}

t_env	*lstlast(t_env *lst)
{
	t_env	*current;
	int		rep;

	rep = 0;
	current = lst;
	while (current != NULL)
	{
		if (current->next == NULL)
			return (current);
		current = current->next;
		rep++;
	}
	return (current);
}
