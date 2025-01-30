# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 15:16:56 by pgiroux           #+#    #+#              #
#    Updated: 2025/01/30 13:06:04 by pgiroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g 

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a


FILE = main quote init exec
SIGNAL = signals
ENV = env
UTIL = free is skip_whitespace
EPUR = epur
TOK = token

GREEN = \033[1;32m
BLUE= \033[1;34m
RED = \033[1;31m
NC = \033[0m

INCLUDE = ./libft/libft.a

FILE_DIR = ./src/
SIGNAL_DIR = ./signals/
ENV_DIR = ./env/
UTIL_DIR = ./utils/
EPUR_DIR = ./epur/
TOK_DIR = ./token/

OBJ_DIR = ./obj/



FILES = $(addprefix $(FILE_DIR), $(addsuffix .c, $(FILE)))
SIGNALS = $(addprefix $(SIGNAL_DIR), $(addsuffix .c, $(SIGNAL)))
ENVS = $(addprefix $(ENV_DIR), $(addsuffix .c, $(ENV)))
EPURS = $(addprefix $(EPUR_DIR), $(addsuffix .c, $(EPUR)))
UTILS = $(addprefix $(UTIL_DIR), $(addsuffix .c, $(UTIL)))
TOKS = $(addprefix $(TOK_DIR), $(addsuffix .c, $(TOK)))


OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILE)))
SIGNAL_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SIGNAL)))
ENV_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(ENV)))
EPUR_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(EPUR)))
UTIL_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(UTIL)))
TOK_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(TOK)))


all : $(NAME)
	
$(OBJ_DIR)%.o: $(FILE_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(OBJ_DIR)%.o: $(SIGNAL_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$@ : $(GREEN)[OK]$(NC)"
	
$(OBJ_DIR)%.o: $(ENV_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(OBJ_DIR)%.o: $(EPUR_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(OBJ_DIR)%.o: $(UTIL_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(OBJ_DIR)%.o: $(TOK_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(OBJS) $(SIGNAL_OBJS) $(ENV_OBJS) $(UTIL_OBJS) $(EPUR_OBJS) $(TOK_OBJS)
	@$(CC) $(CFLAGS) -lreadline $(OBJS) $(SIGNAL_OBJS) $(ENV_OBJS) $(UTIL_OBJS) $(EPUR_OBJS) $(TOK_OBJS) $(INCLUDE) -o  $(NAME)
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