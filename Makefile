# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 15:06:49 by ndo-vale          #+#    #+#              #
#    Updated: 2024/05/29 19:18:09 by ndo-vale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g
RM	= rm -rf

SRC_DIR	= src
SRCS		= $(SRC_DIR)/main.c $(SRC_DIR)/stack_operations.c \
			$(SRC_DIR)/parse_stack.c $(SRC_DIR)/swappers.c \
			$(SRC_DIR)/pushers.c $(SRC_DIR)/rotaters.c \
			$(SRC_DIR)/reverse_rotaters.c $(SRC_DIR)/sort_stack.c \
			$(SRC_DIR)/push_cheapest.c $(SRC_DIR)/find_cheapest.c \
			$(SRC_DIR)/utils.c
OBJS		= $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -s -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -s clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make -s fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
