/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:41:27 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/29 10:41:28 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EPUR_H
# define EPUR_H
# include "../minishell.h"

int		len_str(char *str);
char	*epur_strcpy(char *src, char *dest, int lens, int i);
int		epur_len(char *str);
char	*epur(char *str);

#endif