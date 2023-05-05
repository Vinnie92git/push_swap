# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinni <vinni@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 21:08:22 by vinni             #+#    #+#              #
#    Updated: 2023/05/05 17:54:22 by vinni            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOURS #
GREEN = \033[0;32m
COLOR_OFF = \033[0m

# VARIABLES #
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./include -I ./libft/include
NAME = push_swap
INCLUDE = include/

# OBJECTS #
SRC = cost.c errors.c main.c move.c position.c push.c reverse_rotate.c \
		rotate.c sort.c stack_utils.c stack.c swap.c tiny_sort.c utils.c

SRC_PATH = src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

# RULES #
all: $(NAME)

$(LIBFT): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(LIBFT)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)#### push_swap has been created ####$(COLOR_OFF)"

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME) 
	@echo "$(GREEN)#### push_swap cleaned successfuly ####$(COLOR_OFF)"

re: fclean all

.PHONY: all clean fclean re
