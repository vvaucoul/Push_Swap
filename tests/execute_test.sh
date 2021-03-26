# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    execute_test.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 12:50:47 by vvaucoul          #+#    #+#              #
#    Updated: 2021/03/24 11:14:19 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make -C ../ > /dev/null
cd .. && make random > /dev/null
cd - > /dev/null

NBARGS=$#

if [ ${NBARGS} != "3" ]
then
	echo -n
	#echo "- USAGE : ./execute_test Numbers Min Max (+ bonus flags)"
else
	NBR=$(eval ".././random_nbr $1 $2 $3")
	ARG=$NBR
	echo "Test with : " $ARG
	sleep 1
	.././push_swap $ARG | .././checker $ARG
	exit
fi

if [ ${NBARGS} != "4" ]
then
	echo "- USAGE : ./execute_test Numbers Min Max (+ bonus flags)"
else
	NBR=$(eval ".././random_nbr $1 $2 $3")
	BONUS=$4
	echo "Bonus flag : " $BONUS
	ARG=$NBR
	echo "Test with : " $ARG " | and : " $BONUS
	sleep 1
	.././push_swap $ARG | .././checker $BONUS $ARG
	exit
fi
