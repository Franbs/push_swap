# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 12:36:38 by fbanzo-s          #+#    #+#              #
#    Updated: 2025/03/25 16:55:42 by fbanzo-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = push_swap.c parser.c operations.c operations2.c utils.c \
node.c stack.c algorithm.c print.c utils_sorted.c \
stack_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

clean: 
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
