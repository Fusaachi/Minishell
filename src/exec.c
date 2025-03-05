/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:26:25 by pgiroux           #+#    #+#             */
/*   Updated: 2025/03/05 14:06:27 by pfranke          ###   ########.fr       */
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

void	main_exec(t_data *data)
{
	//split the problem into smaller problems
	t_cmd_exec	*current_cmd;
	int i = 0;
	//trim all of the args char *
	while(data->cmd_first->args[i])
	{
		data->cmd_first->args[i] = ft_strtrim(data->cmd_first->args[i], " ");
		i++;
	}
	current_cmd = data->cmd_first;
	while (current_cmd)
	{
		if (current_cmd->type == CMD && is_builtin(current_cmd->args[0]))
		{
			if (exec_builtin(data, current_cmd) == 1)
				break ;
		}	
		else if (current_cmd->type == CMD)
		{
			if (exec_one(data, current_cmd) == 1)
			{
				printf("MiniPaul : Command not found\n");
				break ;
			}
		}
		current_cmd = current_cmd->next;
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
