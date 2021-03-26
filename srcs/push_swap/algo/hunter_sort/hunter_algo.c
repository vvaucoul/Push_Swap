/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:49:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 13:30:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** Declarations
*/

static int hunter_median(int *heap, UINT size, UINT div)
{
	int *tab;
	int middle;
	int i;

	i = 0;
	if (!(tab = malloc(sizeof(int) * size + 1)))
		return (-1);
	while (i < size)
	{
		tab[i] = heap[i];
		++i;
	}
	tab[i] = 0;
	tab = ft_select_sort(tab, size);
	middle = tab[size / div];
	free(tab);
	return (middle);
}

/*
** Sort Chunk
*/

static int sort_heap_a(t_val *val, int size)
{
	int median;
	int	median_f;
	t_bool heap_b_is_empty;
	UINT init_size = size;

	heap_b_is_empty = val->size_b <= 0 ? TRUE : FALSE;
	median = hunter_median(val->a, size, 2);
	median_f = hunter_median(val->a, size, 4);

	int i = 0;
	int pushed_a = 0;
	int count_b = 0;
	while (i < init_size)
	{
		if (val->a[0] < median)
		{
			pb(val, TRUE);
			++count_b;
		}
		else if (val->a[0] >= median && hunter_median_under(val->a, val->size_a, median))
		{
			if (val->size_b > 1 && heap_b_is_empty && val->b[0] < median_f)
				rr(val, TRUE);
			else
				ra(val, TRUE);
			++pushed_a;
		}
		++i;
	}

	while (pushed_a > 0 && val->size_a != init_size - val->size_b && !heap_is_sorted(val->a, val->size_a))
	{
		rra(val, TRUE);
		--pushed_a;
	}
	return (size - count_b);
}

static int sort_heap_b(t_val *val, int size)
{
	int median;
	UINT init_size = size;
	int i = 0;
	int count_a = 0;
	int count_b = 0;
	if ((init_size >= 1 && init_size <= 2) || check_heap_reverse_sort(val->b, init_size))
	{
		while (i < init_size)
		{
			pa(val, TRUE);
			++i;
		}
		hunter_algo(val, size);
		return (0);
	}
	else if (val->size_b == 3)
	{
		hunter_sort_three_b(val);
		return (0);
	}

	median = hunter_median(val->b, size, 2);


	i = 0;
	while (i < size)
	{
		if (val->b[0] >= median)
		{
			pa(val, TRUE);
			++count_a;
		}
		else if (val->b[0] < median && hunter_median_upper(val->b, size, median))
		{
			rb(val, TRUE);
			++count_b;
		}
		++i;
	}
	i = 0;
	while (i < count_b && val->size_b != size - count_a && !heap_is_reverse_sorted(val->b, val->size_b))
	{
		rrb(val, TRUE);
		++i;
	}
	hunter_algo(val, count_a);
	sort_heap_b(val, size - count_a);
	return (0);
}

int	hunter_algo(t_val *val, int size)
{
	t_hunter hunter;

	if (size == 1 || check_heap_is_sorted(val->a, val->size_a))
		return (1);
	else if (size == 2)
	{
		if (val->size_b > 1 && val->b[0] < val->b[1])
			return (ss(val, TRUE));
		return (sa(val, TRUE));
	}
	else if (size == 3)
		return (hunter_sort_three_a(val));
	hunter.count_a = sort_heap_a(val, size);
	hunter_algo(val, hunter.count_a);
	hunter.count_b = size - hunter.count_a;
	sort_heap_b(val, hunter.count_b);
	return (0);
}
