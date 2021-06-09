/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ranom_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:18:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/18 14:28:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int add_nbr(int *nbr, int new_nbr)
{
    static int index = 0;
    int i;

    i = 0;
    while (i < index)
    {
        if (nbr[i] == new_nbr)
            return (1);
        ++i;
    }
    nbr[index] = new_nbr;
    nbr[index + 1] = 0;
    ++index;
    return (0);
}

int main(int argc, char const *argv[])
{
    int *nbr;
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    if (argc != 4)
    {
        printf("Usage :\t[1] - Nb numbers\n\t[2] - Min Value\n\t[3] - Max Value\n");
        return (-1);
    }
    nbr = calloc(sizeof(int), atoi(argv[1]) + 1);
    srand(time(NULL));
    for (size_t i = 0; i < (size_t)atoi(argv[1]); i++)
    {
        add_nbr(nbr, (rand() % (max + 1 - min)) + min);
    }
    for (size_t i = 0; nbr[i]; i++) {
        printf("%d ", nbr[i]);
    }
    return 0;
}
