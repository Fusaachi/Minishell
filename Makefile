# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 15:16:56 by pgiroux           #+#    #+#              #
#    Updated: 2025/01/06 10:49:29 by pgiroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g 

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a


FILE = main analyserlexical

GREEN = \033[1;32m
BLUE= \033[1;34m
RED = \033[1;31m
NC = \033[0m

INCLUDE = ./libft/libft.a

FILE_DIR = ./src/
OBJ_DIR = ./obj/

FILES = $(addprefix $(FILE_DIR), $(addsuffix .c, $(FILE)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILE)))

all : $(NAME)
	
$(OBJ_DIR)%.o: $(FILE_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -lreadline $(OBJS) $(INCLUDE) -o  $(NAME)
	@echo "\n$(BLUE)=============================================$(NC)\n"
	

$(LIBFT):
	@make -C $(LIBFT_PATH) all
	@clear
	@echo "\n$(BLUE)================= [ START ] =================$(NC)\n"
	@echo "libft : $(GREEN)[OK]$(NC)"

clean :
	@make clean -C ./libft
	@clear
	@echo "$(RED)========== [ OBJECT DELETED ] ==========$(NC)"
	rm -rf $(OBJ_DIR)
	@echo "clean -C ./libft"
	@echo "$(RED)========================================$(NC)"
	
fclean : clean
	@make fclean -C ./libft
	@clear
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"
	rm -f $(NAME) 
	@echo "fclean -C ./libft"
	@echo "$(RED)=============================================$(NC)"
	

re : fclean all

	
.PHONY : all clean fclean re