/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <ksarnyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:18:51 by ksarnyts          #+#    #+#             */
/*   Updated: 2021/03/23 16:05:50 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *stack, int size)
{
	int i;

	i = 0;
	while (i++ < size - 1)
	{
		if (*((int *)stack->next->content)\
				< *((int *)stack->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_rev_sort(t_list *stack, int size)
{
	int i;

	i = 0;
	while (i++ < size - 1)
	{
		if (*((int *)stack->next->content)\
				> *((int *)stack->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_mid_low(t_list *stack, int mid)
{
	printf("# Heap Is - UNDER - Median | Size %d | Middle %d\n", ft_lstsize(stack), mid);
	while (stack)
	{
		if (*((int *)stack->content) < mid)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_mid_up(t_list *stack, int mid)
{
	printf("# Heap Is - UPPER - Median | Size %d | Middle %d\n", ft_lstsize(stack), mid);
	while (stack)
	{
		if (*((int *)stack->content) >= mid)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	stack_is_rev_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (*((int *)stack_a->next->content)\
				> *((int *)stack_a->content))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
