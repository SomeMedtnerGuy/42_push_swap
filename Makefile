# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 15:06:49 by ndo-vale          #+#    #+#              #
#    Updated: 2024/05/21 15:13:13 by ndo-vale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_BONUS = checker
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g
RM	= rm -rf

SRC_DIR	= src
SRCS		= $(SRC_DIR)/main.c $(SRC_DIR)/stack_operations.c \
			$(SRC_DIR)/parse_stack.c $(SRC_DIR)/swappers.c \
			$(SRC_DIR)/pushers.c $(SRC_DIR)/rotaters.c \
			$(SRC_DIR)/reverse_rotaters.c
SRC_BONUS_DIR	= src_bonus
SRCS_BONUS	= $(SRC_BONUS_DIR)/main.c
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus
