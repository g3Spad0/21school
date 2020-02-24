# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 19:57:44 by sjamie            #+#    #+#              #
#    Updated: 2019/11/12 19:57:45 by sjamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= checker
NAME1			= push_swap

CC				= gcc -Wall -Werror -Wextra
HEADER			= includes/
CFLAGS			= -I $(HEADER)

SRC				= src/checker/main.c \
				  src/init.c \
				  src/checker/composition.c \
				  src/functions/s.c \
				  src/functions/p.c \
				  src/functions/r.c \
				  src/functions/rr.c \
				  gnl/get_next_line.c

SRC1			= src/push_swap/main.c \
				  src/push_swap/sorting.c \
				  src/push_swap/helps.c \
				  src/push_swap/sorting_init.c \
				  src/push_swap/bubble_sort.c \
				  src/push_swap/need.c \
				  src/push_swap/calc.c \
				  src/functions/s.c \
				  src/functions/p.c \
				  src/functions/r.c \
				  src/functions/rr.c \
				  src/init.c \
				  gnl/get_next_line.c

OBJ = $(patsubst %.c,%.o,$(SRC))

OBJ1 = $(patsubst %.c,%.o,$(SRC1))

all: $(NAME) $(NAME1)

$(NAME): lib $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L gnl/libft/ -lft

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) -L gnl/libft/ -lft

lib:
	make -C gnl/libft

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJ1)
	make -C gnl/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME1)
	make -C gnl/libft fclean

re: fclean all

.PHONY: clean fclean all re
