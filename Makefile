# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahoareau <ahoareau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/13 08:53:07 by ahoareau          #+#    #+#              #
#    Updated: 2016/02/22 16:27:13 by ahoareau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit
CC = gcc -Wall -Werror -Wextra
SRC = src/*.c
OBJ = *.o
INC = ./inc/

all: $(NAME)

$(NAME):
		$(CC) -I$(INC) -c $(SRC)
		$(CC) $(OBJ) -o $(NAME)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re:	fclean all
