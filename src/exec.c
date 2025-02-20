/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:26:25 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/20 13:07:31 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char *pathfinder(char *cmd)
{
	char	*path;
	char	*tmp;
	char	**path_tab;
	int		i;

	i = 0;
	path = NULL;
	tmp = NULL;
	path_tab = ft_split(getenv("PATH"), ':');
	printf("path_tab = %s\n", path_tab[0]);
	while (path_tab[i])
	{
		tmp = ft_strjoin(path_tab[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			free_tab(path_tab);
			printf("path = %s\n", path);
			return (path);
		}
		free(path);
		i++;
	}
	free_tab(path_tab);
	return ("NUL");
}

int	exec_one(t_data *data)
{
	int	pid;
	int	status;
	if (data->cmd_first->type == CMD)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("cmd de fou = %s\n", pathfinder(data->cmd_first->cmd));
			exit(execve(pathfinder(data->cmd_first->cmd),data->cmd_first->args ,envmaker(data->e_first)));
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
			printf("jsuis pas sense etre la\n");
		}
	}
	return (EXIT_FAILURE);
}

void	main_exec(t_data *data)
{
	//small code that prints all data->cmd_first->args
	int i = 0;
	while (data->cmd_first->args[i])
	{
		printf("args[%d] = %s\n", i, data->cmd_first->args[i]);
		i++;
	}
	
	if(data->cmd_first->type == CMD)
	{
		if (exec_one(data) == EXIT_FAILURE)
			ft_putstr_fd("MiniPaul: command not found\n", 2);
	}
}

bool	pipe_pars(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			check_quote(str, &i);
		if (str[i] == '|')
		{
			i++;
			if (str[i] == '|' || !str[i] || str[0] == '|')
			{
				ft_putstr_fd("MiniPaul: parse error near `|'\n", 2);
				return (false);
			}
		}
		else if (str[i])
			i++;
	}
	return (true);
}
