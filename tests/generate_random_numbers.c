/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_random_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:18:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/10/28 17:58:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../includes/core.h"

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

static int init(int argc, char const *argv[])
{
	if (argc != 4)
	{
		write(1, "Usage :\t[1] - Nb numbers \
		\n\t[2] - Min Value\n\t[3] - Max Value\n",
			  63);
		return (-1);
	}
	if (ft_atoi(argv[3]) - ft_atoi(argv[2]) < ft_atoi(argv[1]))
	{
		write(1, "- Your numbers can't be < to NB numbers\n", 41);
		return (-1);
	}
	return (0);
}

static int init_prg(int *min, int *max, int *rnbr, char const *argv[])
{
	*min = atoi(argv[2]);
	*max = atoi(argv[3]);
	*rnbr = (rand() % (*max + 1 - *min)) + *min;
	return (0);
}

int main(int argc, char const *argv[])
{
	int *nbr;
	size_t i;
	int min;
	int max;
	int rnbr;

	if ((init(argc, argv)))
		return (-1);
	nbr = malloc(sizeof(int) * ft_atoi(argv[1]) + 4);
	srand(time(NULL));
	i = -1;
	init_prg(&min, &max, &rnbr, argv);
	while (++i < (size_t)(ft_atoi(argv[1])))
		while ((add_nbr(nbr, rnbr) == 1))
			rnbr = (rand() % (max + 1 - min)) + min;
	i = -1;
	while (++i < (size_t)(ft_atoi(argv[1])))
	{
		ft_putnbr_fd(nbr[i], 1);
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
	free(nbr);
	return (0);
}
