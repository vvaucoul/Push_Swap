# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    execute_test.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 12:50:47 by vvaucoul          #+#    #+#              #
#    Updated: 2021/03/21 13:08:25 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make -C ../ > /dev/null
cd .. && make random > /dev/null
cd - > /dev/null

NBARGS=$#

if [ ${NBARGS} != "3" ]
then
	echo "- USAGE : ./execute_test Numbers Min Max"
else
	NBR=$(eval ".././random_nbr $1 $2 $3")
	ARG=$NBR
	echo "Test with : " $ARG
	.././push_swap $ARG | .././checker $ARG
fi
