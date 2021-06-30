clear
make re


clear
echo "CAS 3"
sleep 1
ARG="3 1 2" ; ./push_swap $ARG | ./checker $ARG

sleep 3
clear
echo "CAS 6"

sleep 1
ARG="2 1 3 6 5 8" ; ./push_swap $ARG | ./checker $ARG

sleep 3
clear
echo "CAS 30"

sleep 1
ARG="17 18 13 1 27 19 0 25 26 28 22 11 14 10 6 24 8 3 16 9 29 23 5 15 7 2 4 12 20 21" ; ./push_swap $ARG | ./checker $ARG

sleep 3
clear
echo "CAS 16"

sleep 1
clear
ARG="4 3 1 2 5" ; ./push_swap $ARG | ./checker $ARG
sleep 3
clear
ARG="9 8 5 13 21 10 30 12 6 2 23 27 19 16 15 11" ; ./push_swap $ARG | ./checker $ARG

sleep 1
clear
echo "CAS 100"

sleep 1
clear
ARG="57 40 14 3 86 74 55 35 39 54 25 98 78 43 13 28 11 85 99 10 65 34 95 79 59 75 2 96 27 77 68 18 38 88 33 67 37 52 7 84 24 64 69 23 5 26 16 31 89 22 56 8 0 17 60 20 36 44 53 12 81 1 46 19 21 66 76 58 61 32 70 87 48 80 29 4 82 49 50 71 94 41 83 51 30 73 97 42 63 72 15 45 9 47 91 93 62 90 6 92" ; ./push_swap $ARG | ./checker $ARG
sleep 3
clear
ARG="95 67 3 78 5 33 77 65 72 71 46 51 24 52 31 56 82 49 30 76 96 12 59 16 62 32 39 58 98 2 69 94 54 23 0 11 6 80 79 60 55 1 20 4 19 48 28 61 53 99 17 34 37 27 74 90 21 18 81 45 68 36 10 42 75 25 7 8 88 14 15 22 63 26 97 38 70 40 86 92 64 91 50 44 83 73 9 84 66 85 41 43 47 93 29 89 87 35 13 57 " ; ./push_swap $ARG | ./checker $ARG


####

# Push swap va écrire sur 1 les opérations pour correctement trier la pile
#
# pendant ce temps, checker récupère ces opérations et va trier la pile.
# A la fin, checker afficher KO ou OK et le nombre d'opérations en prime
#
# Bonus visuel a faire donc dans checker
