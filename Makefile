# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 15:36:19 by kzouggar          #+#    #+#              #
#    Updated: 2019/06/18 21:27:05 by kzouggar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = checker.c\
main.c\
mouving.c\
solving.c
OBJ = $(patsubst %.c, %.o, $(SRCS))
CFLAGS = -Wall -Wextra -Werror
CC = gcc $(CFLAGS)


all : $(NAME)

$(NAME) : $(OBJ)
	Make -C libft
	$(CC) -o $(NAME) $(SRCS) libft/libft.a

clean :
	Make -C libft clean
	rm -f $(OBJ)

fclean : clean
	Make -C libft fclean
	rm -f $(NAME)

re : fclean all
