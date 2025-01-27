/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:31:33 by ncolomer          #+#    #+#             */
/*   Updated: 2025/01/08 12:39:19 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}					t_list;

int				ft_isalpha(const int c);

int				ft_isdigit(const int c);

int				ft_isalnum(const int c);

int				ft_isascii(const int c);

int				ft_isprint(const int c);

void			*ft_memset(void *ptr, int value, size_t num);

size_t			ft_strlen(const char *str);

size_t			ft_strlen_exclude(const char *str, char c);

void			ft_bzero(void *ptr, size_t num);

void			*ft_memcpy(void *destination, const void *source, size_t num);

void			*ft_memmove(void *destination, const void *source, size_t num);

size_t			ft_strlcpy(char *dst, const char *src, size_t size);

size_t			ft_strlcat(char *dst, const char *src, size_t size);

int				ft_tolower(int c);

int				ft_toupper(int c);

char			*ft_strchr(const char *str, int c);

char			*ft_strrchr(const char *str, int c);

int				ft_strncmp(const char *str1, const char *str2, size_t num);

void			*ft_memchr(const void *src, unsigned char c, size_t num);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

char			*ft_strnstr(const char *str, const char *find, size_t len);

int				ft_atoi(const char *str);

void			*ft_calloc(size_t nbr, size_t size);

char			*ft_strdup(const char *str);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_itoa(int n);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

char			**ft_split(char const *s, char c);

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst, t_list *new);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void *));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

char			*get_next_line(int fd);

int				ft_printf(const char *format, ...);

int				ft_strcmp(char *s1, char *s2);

#endif 
