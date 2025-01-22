/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:56:15 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/22 14:55:12 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execone(char *command, char **args, t_env *e_first)
{
	char	**env;
	char	*path;
	int		ret;

	env = envmaker(e_first);
	path = ft_getpath(e_first, command);
	args++;
	ret = execve(path, args, env);
	if (ret == -1)
	{
		perror(args[0]);
	}
	return (0);
}
