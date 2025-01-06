/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyserlexical.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:42:18 by pgiroux           #+#    #+#             */
/*   Updated: 2025/01/06 10:33:40 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*int ft_analyser_lexique( char *str)
{

}
*/
int ft_whitespace(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
            i++;
        else
            return(0);
    }
    return(1);
}

int verif_quote(char *str)
{
    int			squote;
	int			dquote;
    
    squote = ft_check_quote(str, 34);
	dquote = ft_check_quote(str, 39);
    if (squote == 0 && dquote == 0)
        return (0);
    if (squote % 2 == 0 || dquote % 2 == 0)
    {
        printf("il y a une string");
        return (1);
    }
        
    return (0);
}

int ft_check_quote(char *str, int quote)
{
    int i;
    int count;
    
    i = 0;
    count = 0;
    while(str[i])
    {
        if(ft_quote(str[i], quote))
            count++;
        i++;
    }
    return(count);
    
}

int ft_quote(char c, int i)
{
    if (c == i)
        return (1);
    return(0);
}

