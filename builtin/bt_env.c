/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:11:50 by pfranke           #+#    #+#             */
/*   Updated: 2025/03/04 17:53:43 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Prints without escaping ANSI escape sequences
static void	print_escaped_content(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == '\033')
		{
			printf("\\033");
			i++;
		}
		else if (!ft_isprint((unsigned char)str[i]))
		{
			printf("\\x%02x", (unsigned char)str[i]);
			i++;
		}
		else
			putchar(str[i++]);
	}
	putchar('\n');
}

int	bt_env(t_env *env)
{
	t_env	*tmp;

	if (!env)
		return (EXIT_SUCCESS);
	tmp = env;
	while (tmp)
	{
		if (tmp->content)
			print_escaped_content(tmp->content);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
