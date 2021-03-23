/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <ksarnyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:21:32 by ksarnyts          #+#    #+#             */
/*   Updated: 2021/03/23 16:06:00 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			stack_is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (*((int *)stack_a->next->content)\
				< *((int *)stack_a->content))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int			check_duplicates(t_list *stack, int value)
{
	while (stack)
	{
		if (*((int *)stack->content) == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int			check_valid(int ac, char **av, int i, int j)
{
	while (i < ac)
	{
		j = 0;
		if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
			return (0);
		j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j++]))
				return (0);
		}
		i++;
	}
	return (1);
}

static void	sort(int *array, int size)
{
	int i;
	int j;
	int tmp;

	i = 1;
	while (i++ < size)
	{
		j = 0;
		while (++j < size)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
}

int			middle(t_list *stack, int size, int i, int n)
{
	int *array;
	int mid;

	array = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		array[i++] = *((int *)stack->content);
		stack = stack->next;
	}
	sort(array, size);
	mid = array[size / n];
	free(array);
	printf("# Middle Stack [%d]\n", mid);
	return (mid);
}
