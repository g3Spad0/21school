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

NAME			= libftprintf.a

SRC			= src/main.c \
                  src/controls.c \
                  src/script.c \
                  src/helps/system.c \
                  src/helps/is.c \
                  src/helps/convetrs.c \
                  src/helps/pf_itoa.c \
                  src/helps/numbers.c \
                  src/helps/precision.c \
                  src/helps/pf_atoi.c \
                  src/helps/flags.c \
                  src/floats/pf_ftoa.c \
                  src/floats/ftoa_helper.c \
                  src/helps/flags_opt.c \
                  libft/*.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I ./includes/

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

