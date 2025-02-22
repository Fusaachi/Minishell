/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:23:07 by pgiroux           #+#    #+#             */
/*   Updated: 2025/02/22 19:30:38 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../minishell.h"

typedef struct s_data		t_data;
typedef struct s_token		t_token;
typedef struct s_cmd		t_cmd;
typedef struct s_cmd_exec	t_cmd_exec;

typedef struct s_c
{
	char	**strs;
	char	quote;
	size_t	tok;
	size_t	i;
	size_t	j;
}	t_c;

typedef struct s_t
{
	bool	first;
	size_t	i;
	size_t	start;
}	t_t;

struct s_cmd
{
	char		*content;
	size_t		nb_arg;
	t_token		*token;
	t_token		*t_first;
	t_cmd		*next;
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
	bool		first;
};

void	cmd_tok(t_data *data);
void	print(t_data *data, t_cmd *cmd);

t_cmd	*new_cmd(const char *src, size_t size);
t_token	*new_token(const char *src, size_t size);

void	init_c(t_c *c);
t_cmd	*split_cmd(t_data *data, char *str, const char delimiter);
size_t	ft_count_cmd( char *str, const char delimit);
t_cmd	*init_cmd(t_data *data, const char *src, t_c *c, int j);

void	split_token_redir(t_cmd *cmd, const char *str, size_t len, bool first);
void	split_token_space(t_cmd *cmd, const char *str, size_t len, bool first);
void	split_token(t_cmd *cmd, char *str);
void	in_the_quote(char *str, t_t *t);
void	for_the_redir(char *str, t_t *t);

void	type_token(t_cmd *cmd, t_data *data);
void	search_type(t_cmd *cmd, t_token *token, char *str, bool first);
bool	is_type(t_token *token);
bool	same_type(t_cmd *cmd, t_data *data);

#endif