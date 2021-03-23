# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 13:47:36 by ksarnyts          #+#    #+#              #
#    Updated: 2017/01/16 12:56:07 by ksarnyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
SRC =	ft_atoi.c\
		ft_isdigit.c\
		ft_strlen.c\
		create_array.c\
		print_decimal.c\
		print_specifier.c \
		print_unsigned.c \
		print_octal.c \
		print_hex.c \
		print_str.c \
		print_char.c \
		print_letter.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_printhex.c \
		ft_printoct.c \
		ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
