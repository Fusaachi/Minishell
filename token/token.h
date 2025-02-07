/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:23:07 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/07 14:03:54 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../minishell.h"

typedef struct s_data	t_data;
typedef struct s_token	t_token;
typedef struct s_cmd	t_cmd;

typedef struct s_tok
{
	char	**strs;
	char	quote;
	size_t	tok;
	size_t	i;
	size_t	j;
}t_tok;

struct s_cmd
{
	char	*content;
	t_token	*token;
	t_token	*t_first;
	t_cmd	*next;
};

enum	e_type
{
	ARG,
	REDIR_IN,
	INFILE,
	REDIR_OUT,
	OUTFILE,
	APPEND,
	HERE_DOC,
	CMD,
};

struct s_token
{
	enum e_type	type;
	char		*content;
	t_token		*next;
	t_token		*previous;
};

void	init_strcmd(t_tok *t);
size_t	ft_count_cmd( char *str, const char delimit);
t_cmd	*split_cmd(t_data *data, char *str, const char delimiter);
t_cmd	*new_cmd(const char *src, size_t size);
t_cmd	*init_cmd(t_data *data, const char *src, t_tok *t, int j);

t_token *new_token(const char *src, size_t size);

void	cmd_tok(t_data *data);
//t_data	*init_cmd(t_cmd *cmd, t_data *data, char **content);

t_data	*init_token(t_token *token, t_cmd *cmd, t_data *data, char **content);
//t_token	*new_token(t_token *token, char *content, int first);

t_token	*search_type(t_token *token, char *str, int first);
#endif