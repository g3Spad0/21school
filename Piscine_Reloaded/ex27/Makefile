# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 19:55:33 by sjamie            #+#    #+#              #
#    Updated: 2019/09/06 19:55:35 by sjamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = main.c
OBJ = main.o
GCCW = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(GCCW) -c $(SRC)
	ar rc libft.a $(OBJ)
	ranlib libft.a
	$(GCCW) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a

re: fclean all
