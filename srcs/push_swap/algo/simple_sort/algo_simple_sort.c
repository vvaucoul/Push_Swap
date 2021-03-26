/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:20:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 11:25:50 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** // VISUAL UPDATE
**
** if (val->bonus_visualize)
** {
** 	update_visualisation(val, TRUE);
** 	printf("\n\n");
** 	printf(BLUE);
** 	printf(BOLD);
** 	printf("\n-----------------------------\n");
** 	printf(YELLOW " - MIN\t\t"GREEN"%d\n", min);
** 	printf(YELLOW " - NEXT MIN\t"GREEN"%d\n", next_min);
** 	printf(YELLOW " - MAX\t\t"GREEN"%d\n", max);
** 	printf(YELLOW " - swap_b =\t"GREEN"%d\n", swap_b);
** 	printf(YELLOW " - min_found\t"GREEN"%d\n", min_found);
** 	printf(YELLOW " - min_r\t"GREEN"%d\n", min_r(val->a, val->size_a, min));
** 	printf(YELLOW " - min_rr\t"GREEN"%d\n", min_rr(val->a, val->size_a, min));
** 	printf(YELLOW " - HEAP A : size\t"GREEN"%ld\n", val->size_a);
** 	printf(YELLOW " - HEAP B : size\t"GREEN"%ld\n", val->size_b);
** 	printf(BLUE);
** 	printf("-----------------------------\n\n");
** }
** usleep(DEBUG_TIME_TO_WAIT);
*/

static void		min_found(t_val *val, t_ss *ss)
{
	if (ss->min_found == 1)
	{
		ss->min = is_min_value(val->a, val->size_a);
		ss->next_min = is_next_min_value(val->a, val->size_a);
		ss->min_found = 0;
	}
	if (min_r(val->a, val->size_a, ss->min) <
	min_rr(val->a, val->size_a, ss->min))
		ra(val, TRUE);
	else
		rra(val, TRUE);
}

static int		algo_sort(t_val *val, t_ss *ss)
{
	if (val->a[0] == ss->next_min)
	{
		pb(val, TRUE);
		ss->swap_b = 1;
	}
	if (val->a[0] == ss->min)
	{
		ss->min_found = 1;
		pb(val, TRUE);
		if (ss->swap_b == 1)
		{
			sb(val, TRUE);
			ss->swap_b = 0;
		}
	}
	min_found(val, ss);
	if (val->size_a == 0)
	{
		while (val->size_b != 0)
			pa(val, TRUE);
	}
	return (0);
}

int				algo_02(t_val *val)
{
	t_ss ss;

	ss.max = is_max_value(val->a, val->size_a);
	ss.min = is_min_value(val->a, val->size_a);
	ss.next_min = is_next_min_value(val->a, val->size_a);
	ss.min_found = 0;
	ss.swap_b = 0;
	while (heap_solved(val))
		algo_sort(val, &ss);
	return (0);
}
