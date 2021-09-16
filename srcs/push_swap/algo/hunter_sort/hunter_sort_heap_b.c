/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_sort_heap_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:52:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 14:10:03 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

static int		sort_heap_b_special_cases(t_val *val,
UINT init_size, int *i, int size)
{
	if ((init_size >= 1 && init_size <= 2) ||
	check_heap_reverse_sort(val->b, init_size))
	{
		while (i[0] < (int)init_size)
		{
			pa(val, TRUE);
			++i[0];
		}
		hunter_algo(val, size);
		return (0);
	}
	else if (val->size_b == 3)
	{
		hunter_sort_three_b(val);
		return (0);
	}
	return (1);
}

static int		sort_heap_b_loop(t_val *val, t_hunter *hunter, int size)
{
	int i;

	i = 0;
	while (i < (int)size)
	{
		if (val->b[0] >= hunter->median)
		{
			pa(val, TRUE);
			++hunter->pushed_a;
		}
		else if (val->b[0] < hunter->median &&
		hunter_median_upper(val->b, size, hunter->median))
		{
			rb(val, TRUE);
			++hunter->pushed_b;
		}
		++i;
	}
	return (0);
}

int				sort_heap_b(t_val *val, int size)
{
	t_hunter	hunter;
	UINT		init_size;
	int			i;

	init_size = size;
	i = 0;
	if ((sort_heap_b_special_cases(val, init_size, &i, size)) == 0)
		return (0);
	hunter.median = hunter_median(val->b, size, 2);
	hunter.pushed_a = 0;
	hunter.pushed_b = 0;
	sort_heap_b_loop(val, &hunter, size);
	i = 0;
	while (i < hunter.pushed_b && (int)val->size_b != size - hunter.pushed_a
	&& !heap_is_reverse_sorted(val->b, val->size_b))
	{
		rrb(val, TRUE);
		++i;
	}
	hunter_algo(val, hunter.pushed_a);
	sort_heap_b(val, size - hunter.pushed_a);
	return (0);
}
