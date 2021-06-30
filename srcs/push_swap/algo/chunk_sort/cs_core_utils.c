/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_core_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:12:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:29:04 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** Get median of heap (A / B)
*/

int	get_heap_median(int *h)
{
	t_median med;

	med.i = 0;
	med.j = 0;
	med.median = 0;
	while (med.i < ft_tablen(h))
	{
		med.key = h[med.i];
		med.j = 0;
		med.a = 0;
		med.b = 0;
		while (med.j < (int)ft_tablen(h))
		{
			if (h[med.j] > med.key)
				++med.a;
			else
				++med.b;
			if (med.a == med.b)
				med.median = med.key;
			++med.j;
		}
		++med.i;
	}
	return (med.median);
}

int	has_number_inferior_median(int *h, int median)
{
	int i;

	i = 0;
	while (h[i])
	{
		if (h[i] < median)
			return (1);
		++i;
	}
	return (0);
}
