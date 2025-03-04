/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:31:56 by pfranke           #+#    #+#             */
/*   Updated: 2025/03/04 18:31:18 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


char	*pathfinder(char *cmd)
{
	char	*path;
	char	*tmp;
	char	**path_tab;
	int		i;

	tmp = ft_strtrim(cmd, "./");
	if (access(cmd, F_OK) == 0)
	{
		free(tmp);
		return (cmd);
	}
	i = 0;
	path = NULL;
	tmp = NULL;
	path_tab = ft_split(getenv("PATH"), ':');
	while (path_tab[i])
	{
		tmp = ft_strjoin(path_tab[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			ft_free_tab(path_tab);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_tab(path_tab);
	return (NULL);
}

int	exec_one(t_data *data, t_cmd_exec *cmd)
{
	int	pid;
	int	status;

	if (cmd->type == CMD)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(pathfinder(cmd->args[0]), &cmd->args[1],
					envmaker(data->e_first)) == -1)
			{
				printf("that was arg[1] = %s\n", cmd->args[1]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
		}
	}
	return (EXIT_FAILURE);
}
