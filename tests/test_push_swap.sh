# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_push_swap.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 11:55:20 by vvaucoul          #+#    #+#              #
#    Updated: 2021/03/21 12:49:52 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PUSH SWAP TESTEUR
# Made By vvaucoul

#!/bin/sh

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

clear

echo "$BOLDYELLOW - INITIALISATION..."
cd .. > /dev/null
make -C .  > /dev/null
make random > /dev/null
cd - > /dev/null
cp -f ../checker . > /dev/null
cp -f ../random_nbr . > /dev/null
cp -f ../push_swap . > /dev/null
cd .. > /dev/null
make fclean > /dev/null
cd - > /dev/null

# Tests Part

checker_tests()
{
	echo -n "$RESET # ./checker "
	echo $1
	./checker $1;
	echo
	sleep 0.5
}

push_swap_tests()
{
	echo -n "$RESET # ./push_swap "
	echo $1
	./push_swap $1;
	echo
	sleep 0.5
}

echo "$BOLDYELLOW - Basic Checker Tests\n"
sleep 1

checker_tests ''
checker_tests 'test test invalid'
checker_tests '1a2 42'
checker_tests '42           t'
checker_tests 'A'
checker_tests '42 12 24 42'
checker_tests '2147483647'
checker_tests '-2147483648'
checker_tests '9999999999'
checker_tests '18446744073709551615'
checker_tests '-18446744073709551616'

echo "$BOLDYELLOW - Basic Push Swap Tests\n"
sleep 1
push_swap_tests ''
push_swap_tests 'test test invalid'
push_swap_tests '1a2 42'
push_swap_tests '42           t'
push_swap_tests 'A'
push_swap_tests '42 12 24 42'
push_swap_tests '2147483647'
push_swap_tests '-2147483648'
push_swap_tests '9999999999'
push_swap_tests '18446744073709551615'
push_swap_tests '-18446744073709551616'

# End Test

echo "$BOLDYELLOW - Fin des Tests"

rm -f checker > /dev/null
rm -f push_swap  > /dev/null
rm -f random_nbr > /dev/null
