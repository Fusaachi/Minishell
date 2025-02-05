/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:56:15 by pfranke           #+#    #+#             */
/*   Updated: 2025/01/31 09:23:50 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pipe_execone(char *command, char **args, t_env *e_first)
{
	char	**env;
	char	*path;
	int		ret;
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
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
	return (EXIT_SUCCESS);
}
/*
int	pipe_outfile(t_pipe spipe)
{
	int	fds[2];

	pipe(fds);
	if (fork() == 0)
	{
		dup2(fds[1], 1);
		close(fds[0]);
		close(fds[1]);
		pipe_execone(spipe.command, spipe.args, spipe.e_first);
		exit(0);
	}
	else
	{
		dup2(fds[0], 0);
		close(fds[0]);
		close(fds[1]);
	}
	return (0);
}
*/