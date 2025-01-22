/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:10:07 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/22 14:56:26 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "../minishell.h"

char	**envmaker(t_env *e_first);
void	doubletabprintf(char **tab);
char	*ft_getpath(t_env *e_first, char *name);
int		execone(char *command, char **args, t_env *e_first);

#endif