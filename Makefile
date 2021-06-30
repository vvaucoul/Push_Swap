# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 22:02:22 by vvaucoul          #+#    #+#              #
#    Updated: 2021/03/19 15:52:41 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC	= checker
NAMEPS	= push_swap
NAMES = $(NAMEC) $(NAMEPS)


NAMEC_BONUS	= checker_bonus
NAMEPS_BONUS = push_swap_bonus
NAMES_BONUS = $(NAMEC_BONUS) $(NAMEPS_BONUS)

CCO		= gcc -g3 -Wall -Werror -Wextra -I./includes -o

SRCC	=			$(wildcard srcs/core/*.c) \
					$(wildcard srcs/core/debug/*.c) \
					$(wildcard srcs/core/operations/*.c) \
					$(wildcard srcs/core/sort/*.c) \
					$(wildcard srcs/core/init/*.c) \
					$(wildcard srcs/core/utils/*.c) \
					$(wildcard srcs/checker/*.c)

SRCPS	=			$(wildcard srcs/core/*.c) \
					$(wildcard srcs/core/debug/*.c) \
					$(wildcard srcs/core/operations/*.c) \
					$(wildcard srcs/core/init/*.c) \
					$(wildcard srcs/core/utils/*.c) \
					$(wildcard srcs/core/sort/*.c) \
					$(wildcard srcs/push_swap/algo/*.c) \
					$(wildcard srcs/push_swap/algo/chunk_sort/*.c) \
					$(wildcard srcs/push_swap/algo/simple_sort/*.c) \
					$(wildcard srcs/push_swap/*.c)

# ajouter main de PS & checker dans srcs bonus avec visualisation a 1
SRCC_BONUS	=		$(wildcard srcs/core/*.c) \
					$(wildcard srcs/core/debug/*.c) \
					$(wildcard srcs/core/operations/*.c) \
					$(wildcard srcs/core/sort/*.c) \
					$(wildcard srcs/core/utils/*.c) \
					srcs_bonus/checker_bonus.c	\
					srcs_bonus/read_input_bonus.c	\
					$(wildcard srcs_bonus/visualisation/*.c) \
					$(wildcard srcs_bonus/init/*.c)

SRCPS_BONUS = 		$(wildcard srcs/core/*.c) \
					$(wildcard srcs/core/debug/*.c) \
					$(wildcard srcs/core/operations/*.c) \
					$(wildcard srcs/core/utils/*.c) \
					$(wildcard srcs/core/sort/*.c) \
					$(wildcard srcs/push_swap/algo/*.c) \
					$(wildcard srcs/push_swap/algo/chunk_sort/*.c) \
					$(wildcard srcs/push_swap/algo/simple_sort/*.c) \
					srcs/push_swap/solve_heap.c	\
					srcs_bonus/push_swap_bonus.c	\
					$(wildcard srcs_bonus/visualisation/*.c) \
					$(wildcard srcs_bonus/init/*.c)


OBJC	= $(SRCC:%.c=%.o)
OBJPS	= $(SRCPS:%.c=%.o)

OBJC_BONUS	= $(SRCC_BONUS:%.c=%.o)
OBJPS_BONUS	= $(SRCPS_BONUS:%.c=%.o)

TRASH	= $(SRCC:%.c=%.c~) $(SRCPS:.c=.c~)
TRASH_BONUS = $(SRCC_BONUS:%.c=%.c~) $(SRCPS_BONUS:.c=.c~)

all:	$(NAMES)

%.o: %.c
	@$(CCO) $@ $< -c

$(NAMEC): $(OBJC)
	@echo "\033[0;34mmaking checker.a\033[0m"
	@$(CCO) $(NAMEC) $(OBJC)


$(NAMEPS): $(OBJPS)
	@echo "\033[0;35mmaking push_swap.a\033[0m"
	@$(CCO) $(NAMEPS) $(OBJPS)

bonus: $(NAMES_BONUS)

$(NAMEC_BONUS): $(OBJC_BONUS)
	@echo "\033[0;34mmaking [BONUS] checker.a\033[0m"
	@$(CCO) $(NAMEC_BONUS) $(OBJC_BONUS)


$(NAMEPS_BONUS): $(OBJPS_BONUS)
	@echo "\033[0;35mmaking [BONUS] push_swap.a\033[0m"
	@$(CCO) $(NAMEPS_BONUS) $(OBJPS_BONUS)


clean:
	@rm -f $(OBJC) $(OBJPS) $(OBJC_BONUS) $(OBJPS_BONUS)
	@echo "\033[0;31mCleaning object files \033[0m"
	@rm -f $(TRASH) $(TRASH_BONUS)
	@echo "\033[1;33mCleaning the trash\033[0m"

fclean: clean
	@rm -f $(NAMES) $(NAMES_BONUS) random_nbr
	@echo "\033[0;32mClearing executables\033[0m"

random:
	@gcc tests/generate_ranom_numbers.c -o random_nbr

norme:
	norminette srcs/push_swap srcs/checker srcs/core includes/

re: fclean all

rebonus: fclean bonus

.PHONY:			all clean fclean re
