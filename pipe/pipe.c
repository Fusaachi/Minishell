/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:56:15 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/23 14:21:48 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execone(char *command, char **args, t_env *e_first)
{
	char	**env;
	char	*path;
	int		ret;
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		env = envmaker(e_first);
		path = ft_getpath(e_first, command);
		ret = execve(path, args, env);
		if (ret == -1)
		{
			perror(args[0]);
		}
	}
	waitpid(pid, &ret, 0);
	return (0);
}
