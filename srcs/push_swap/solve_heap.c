/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_heap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:01:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/23 12:01:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	solve_heap(t_val *val)
{
	/*
	if (val->size_a <= 1 || !heap_solved(val))
		return (0);
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
	algo_03(val);
	*/

	hunter_algo(val, val->size_a);
//	system("leaks push_swap");
	return (0);
}
