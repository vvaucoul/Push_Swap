/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_heap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:01:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 15:56:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	solve_heap(t_val *val)
{
	if (val->size_a <= 1 || !heap_solved(val))
		return (0);
	if (val->size_a == 2)
	{
		if (val->a[0] > val->a[1])
			return (sa(val, TRUE));
	}
	if (val->size_a <= 3)
	{
		case_three(val);
		return (0);
	}
	if (val->size_a <= 15)
	{
		if (swap_sort(val))
			return (0);
	}
	else
		hunter_algo(val, val->size_a);
	return (0);
}
