# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 12:36:38 by fbanzo-s          #+#    #+#              #
#    Updated: 2025/04/11 13:46:16 by fbanzo-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
RESET   = \033[0m

NAME = push_swap
BONUS = checker
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR) -I.
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_MAIN = push_swap.c
SRC = calculate_costs2.c parser.c operations.c operations2.c utils.c \
      node.c stack.c algorithm.c print.c utils_sorted.c \
      calculate_costs.c stack_utils.c utils2.c
OBJ = $(SRC:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)

BONUS_SRC = checker.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory
	@make -C $(LIBFT_DIR) bonus --no-print-directory

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ) $(OBJ_MAIN) Makefile
	@echo "$(YELLOW)Compilando $@...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_MAIN) -L$(LIBFT_DIR) -lft -o $@
	@echo "$(GREEN)Hecho$(RESET)"

$(BONUS): $(LIBFT) $(OBJ) $(BONUS_OBJ) Makefile
	@echo "$(YELLOW)Compilando $@...$(RESET)"
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJ) -L$(LIBFT_DIR) -lft -o $@
	@echo "$(GREEN)Hecho$(RESET)"

bonus: $(BONUS)

clean:
	@echo "$(RED)Limpiando objetos...$(RESET)"
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@rm -f $(OBJ) $(OBJ_MAIN) $(BONUS_OBJ)

fclean: clean
	@echo "$(RED)Limpiando todo...$(RESET)"
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus