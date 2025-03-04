/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:50:46 by pfranke           #+#    #+#             */
/*   Updated: 2025/03/04 18:18:42 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_builtin(t_data *data, t_cmd_exec *cmd)
{
	if (ft_strcmp(cmd->args[0], "echo") == 0)
	{
		bt_echo(cmd->args);
		return (1);
	}
	else if (ft_strcmp(cmd->args[0], "cd") == 0)
	{
		bt_cd(cmd->args[1]);
		return (1);
	}
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
	{
		bt_pwd();
		return (1);
	}
	else if (ft_strcmp(cmd->args[0], "export") == 0)
	{
		data->e_first = bt_export(data->e_first, cmd->args[1]);
		return (1);
	}
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
	{
		data->e_first = bt_unset(cmd->args[1], data->e_first);
		return (1);
	}
	else if (ft_strcmp(cmd->args[0], "env") == 0)
	{
		bt_env(data->e_first);
		return (1);
	}
	else if (ft_strcmp(cmd->args[0], "exit") == 0)
	{
		bt_exit(data, cmd->args);
		return (1);
	}
	return (0);
}
