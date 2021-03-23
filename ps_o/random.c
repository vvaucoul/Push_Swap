/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:22:27 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/02/13 15:23:29 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

void	print_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", array[i]);
		i++;
	}
	ft_printf("\n");
}

int		check_array(int *array, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (array[j] == array[i])
			return (0);
		j++;
	}
	return (1);
}

int		*create_stack_a(int min, int max, int size)
{
	int *array;
	int i;

	array = (int *)malloc(sizeof(int) * size);
	srand(time(NULL));
	i = 0;
	while (i < size)
	{
		array[i] = min + rand() % (max - min);
		if (check_array(array, i))
			i++;
	}
	return (array);
}

int		main(int argc, char **argv)
{
	int *stack_a;
	int size;

	if (argc != 4)
		return (ft_printf("wrong input\n"));
	size = ft_atoi(argv[3]);
	stack_a = create_stack_a(ft_atoi(argv[1]), ft_atoi(argv[2]),\
			ft_atoi(argv[3]));
	print_array(stack_a, size);
	return (0);
}
