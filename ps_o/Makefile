# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 13:47:36 by ksarnyts          #+#    #+#              #
#    Updated: 2017/02/13 16:50:58 by ksarnyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
       commands.c \
       validation.c \
       sort_check_functions.c\
       sort_divide.c

SRC2 = checker.c \
       commands.c \
       validation.c \
       check_read_print.c

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	cd libft/ && $(MAKE)
	cd libft/printf/ && $(MAKE)
	gcc $(CFLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ) libft/libft.a libft/printf/libftprintf.a
	gcc -o checker $(OBJ2) libft/libft.a libft/printf/libftprintf.a

%.o:%.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)
	cd libft/ && $(MAKE) clean
	cd libft/printf/ && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f checker
	cd libft/ && rm -f libft.a
	cd libft/printf/ && rm -f libftprintf.a

re: fclean all
