/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_sort_heap_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:39:19 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 14:08:51 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

static void		init_sort_heap_a(t_val *val, t_hunter *hunter, int size, int *i)
{
	hunter->heap_b_is_empty = val->size_b <= 0 ? TRUE : FALSE;
	hunter->median = hunter_median(val->a, size, 2);
	hunter->median_b = hunter_median(val->a, size, 4);
	hunter->pushed_a = 0;
	hunter->pushed_b = 0;
	*i = 0;
}

static int		sort_heap_a_loop(t_val *val, t_hunter *hunter, int *i,
UINT init_size)
{
	while (*i < (int)init_size)
	{
		if (val->a[0] < hunter->median)
		{
			pb(val, TRUE);
			++hunter->pushed_b;
		}
		else if (val->a[0] >= hunter->median &&
		hunter_median_under(val->a, val->size_a, hunter->median))
		{
			if (val->size_b > 1 && hunter->heap_b_is_empty &&
			val->b[0] < hunter->median_b)
				rr(val, TRUE);
			else
				ra(val, TRUE);
			++hunter->pushed_a;
		}
		++(*i);
	}
	return (0);
}

int				sort_heap_a(t_val *val, int size)
{
	t_hunter	hunter;
	UINT		init_size;
	int			i;

	init_size = size;
	init_sort_heap_a(val, &hunter, size, &i);
	sort_heap_a_loop(val, &hunter, &i, init_size);
	while (hunter.pushed_a > 0 && val->size_a != init_size - val->size_b &&
	!heap_is_sorted(val->a, val->size_a))
	{
		rra(val, TRUE);
		--hunter.pushed_a;
	}
	return (size - hunter.pushed_b);
}
