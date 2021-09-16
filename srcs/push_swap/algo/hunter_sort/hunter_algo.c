/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:49:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 13:54:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** HUNTER ALGO
*/

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
	hunter.pushed_a = sort_heap_a(val, size);
	hunter_algo(val, hunter.pushed_a);
	hunter.pushed_b = size - hunter.pushed_a;
	sort_heap_b(val, hunter.pushed_b);
	return (0);
}
