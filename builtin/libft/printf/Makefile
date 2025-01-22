NAME = libftprintf.a


SRCS = ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c \
		ft_putptr.c ft_putstr.c printuntilnext.c \
		ft_putnbru.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -w

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
