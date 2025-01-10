/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:32:56 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/10 14:34:34 by pgiroux          ###   ########.fr       */
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
	char	*key;
	char	*value;
	t_env	*next;
};

t_data	*init_env(t_env *lst, t_data *data, char **envp);
t_env	*lstnew(char *content);
char	*env_value(char *str);
char	*env_key(char *str);

#endif