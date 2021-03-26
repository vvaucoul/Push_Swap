# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 22:02:22 by vvaucoul          #+#    #+#              #
#    Updated: 2021/03/26 13:53:16 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC	= checker
NAMEPS	= push_swap
NAMER	= random_nbr

NAMES = $(NAMEC) $(NAMEPS)

CCO		= gcc -g3 -o #-Wall -Werror -Wextra -I./includes -o

SRCC	=		srcs/core/solved.c \
				srcs/core/debug/print_heap.c \
				srcs/core/operations/push.c	\
				srcs/core/operations/reverse_rotate.c	\
				srcs/core/operations/rotate.c	\
				srcs/core/operations/swap.c	\
				srcs/core/sort/ft_select_sort.c	\
				srcs/core/init/ft_parse_args.c	\
				srcs/core/init/init_check_args.c	\
				srcs/core/init/init_param.c	\
				srcs/core/utils/free.c	\
				srcs/core/utils/ft_atoi.c	\
				srcs/core/utils/ft_atoull.c	\
				srcs/core/utils/ft_itoa.c	\
				srcs/core/utils/tab_utils_move.c	\
				srcs/core/utils/tab_utils.c	\
				srcs/core/utils/utils_libft.c	\
				srcs/core/utils/utils.c	\
				srcs/core/visualisation/visu_bars_utils.c	\
				srcs/core/visualisation/visu_bars.c	\
				srcs/core/visualisation/visu_heaps_last_action_text.c	\
				srcs/core/visualisation/visu_heaps_last_action.c	\
				srcs/core/visualisation/visu_heaps.c	\
				srcs/core/visualisation/visu_usefull_functions.c	\
				srcs/core/visualisation/visu_utils.c	\
				srcs/core/visualisation/visualisation.c	\
				srcs/checker/checker.c	\
				srcs/checker/read_input_utils.c	\
				srcs/checker/read_input.c

SRCPS	=		srcs/core/solved.c	\
				srcs/core/debug/print_heap.c \
				srcs/core/operations/push.c	\
				srcs/core/operations/reverse_rotate.c	\
				srcs/core/operations/rotate.c	\
				srcs/core/operations/swap.c	\
				srcs/core/init/ft_parse_args.c	\
				srcs/core/init/init_check_args.c	\
				srcs/core/init/init_param.c	\
				srcs/core/utils/free.c	\
				srcs/core/utils/ft_atoi.c	\
				srcs/core/utils/ft_atoull.c	\
				srcs/core/utils/ft_itoa.c	\
				srcs/core/utils/tab_utils_move.c	\
				srcs/core/utils/tab_utils.c	\
				srcs/core/utils/utils_libft.c	\
				srcs/core/utils/utils.c	\
				srcs/core/sort/ft_select_sort.c	\
				srcs/push_swap/algo/case_three.c	\
				srcs/push_swap/algo/chunk_sort/algo_chunk_sort.c	\
				srcs/push_swap/algo/chunk_sort/cs_core_utils.c	\
				srcs/push_swap/algo/chunk_sort/cs_loop.c	\
				srcs/push_swap/algo/chunk_sort/cs_step2_utils.c	\
				srcs/push_swap/algo/simple_sort/algo_simple_sort.c	\
				srcs/push_swap/algo/simple_sort/ss_utils.c	\
				srcs/push_swap/algo/swap_sort/swap_sort.c	\
				srcs/push_swap/solve_heap.c \
				srcs/push_swap/push_swap.c	\
				srcs/push_swap/algo/hunter_sort/hunter_algo.c \
				srcs/push_swap/algo/hunter_sort/hunter_sort_three.c \
				srcs/push_swap/algo/hunter_sort/hunter_utils.c \
				srcs/push_swap/algo/hunter_sort/hunter_utils_02.c \
				srcs/push_swap/algo/hunter_sort/hunter_sort_heap_a.c \
				srcs/push_swap/algo/hunter_sort/hunter_sort_heap_b.c

SRCR	=		tests/generate_random_numbers.c \
				srcs/core/utils/utils_libft.c \
				srcs/core/utils/ft_atoi.c

OBJC	= $(SRCC:%.c=%.o)
OBJPS	= $(SRCPS:%.c=%.o)
OBJR	= $(SRCR:%.c=%.o)

TRASH	= $(SRCC:%.c=%.c~) $(SRCPS:.c=.c~) $(SRCR:.c=.c~)

all:	$(NAMES)

%.o: %.c
	@$(CCO) $@ $< -c

$(NAMEC): $(OBJC)
	@echo "\033[0;34mmaking checker\033[0m"
	@$(CCO) $(NAMEC) $(OBJC)

$(NAMEPS): $(OBJPS)
	@echo "\033[0;35mmaking push_swap\033[0m"
	@$(CCO) $(NAMEPS) $(OBJPS)

$(NAMER): $(OBJR)
	@echo "\033[0;34mmaking Random NBR\033[0m"
	@$(CCO) $(NAMER) $(OBJR)

clean:
	@rm -f $(OBJC) $(OBJPS) $(OBJR)
	@echo "\033[0;31mCleaning object files \033[0m"
	@rm -f $(TRASH)
	@echo "\033[1;33mCleaning the trash\033[0m"

fclean: clean
	@rm -f $(NAMES) $(NAMER)
	@echo "\033[0;32mClearing executables\033[0m"

random: $(NAMER)

norme:
	norminette srcs/push_swap srcs/checker srcs/core includes/

re: fclean all

.PHONY:			all clean fclean re
