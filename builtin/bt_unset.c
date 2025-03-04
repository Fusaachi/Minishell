/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:01:07 by pfranke           #+#    #+#             */
/*   Updated: 2025/03/04 18:19:04 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#include <stdlib.h> // Pour free

// Hypothèse : ft_strncmp et ft_strlen sont des fonctions de ta libft
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

// Fonction pour libérer un nœud t_env
static void	triple_free(t_env *node)
{
	if (node)
	{
		if (node->key)
			free(node->key);
		if (node->content)
			free(node->content);
		free(node);
	}
}

t_env	*bt_unset(char *name, t_env *env)
{
	t_env	*tmp;
	t_env	*prev;

	if (!env || !name) // Vérification des arguments
		return (env);
	tmp = env;
	prev = NULL; // Initialisé à NULL car on n’a pas encore de précédent
	while (tmp)
	{
		if (ft_strncmp(tmp->key, name, ft_strlen(name)) == 0
			&& ft_strlen(tmp->key) == ft_strlen(name)) // Comparaison exacte
		{
			if (tmp == env) // Cas où c’est le premier élément
			{
				env = env->next;
				triple_free(tmp);
				return (env);
			}
			prev->next = tmp->next; // Relie le précédent au suivant
			triple_free(tmp);
			return (env);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (env); // Si rien n’est trouvé, retourne la liste inchangée
}
