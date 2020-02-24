# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 19:29:46 by sjamie            #+#    #+#              #
#    Updated: 2019/10/16 16:52:40 by matruman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fillit

CC				= gcc
HEADER			= includes/
CFLAGS			= -Wall -Wextra -Werror -I $(HEADER)

SRC				= src/algoritm.c \
				  src/fillit_strsplit.c \
				  src/main.c \
				  src/checker.c \
				  src/helps.c \
				  src/position.c \
				  src/handler.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

lib:
	make -C libft

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
