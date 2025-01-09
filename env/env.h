/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:32:56 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/09 13:52:45 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../minishell.h"

typedef struct s_data	t_data;
typedef struct s_env	t_env;
struct s_env
{
	char	*content;
	t_env	*next;
};

t_data	*init_env(t_env *lst, t_data *data, char **envp);
t_env	*lstnew(char *content);

#endif