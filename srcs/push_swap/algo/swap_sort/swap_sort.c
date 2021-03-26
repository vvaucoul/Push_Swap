/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:13:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 11:26:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** [0] si l'algo swap peut être effectué -> sinon, return
** [1] Rotate pile A
** [2] si valeur 0 > valeur 1 -> swap
** [3] si la pile est triée, rotate jusqu'a 0 == min
*/

int		swap_sort(t_val *val)
{
	UINT		i;
	int			min_value;
	int			s_rotation;

	i = 0;
	while (val->size_a > 3)
	{
		if (!heap_solved(val))
			return (0);
		min_value = get_min_value(val->a, val->size_a);
		s_rotation = select_rotation(val->a, min_value, val->size_a);
		if (val->a[0] == min_value)
			pb(val, TRUE);
		else if (s_rotation)
			rra(val, TRUE);
		else
			ra(val, TRUE);
		++i;
	}
	case_three(val);
	if (val->b[0] < val->b[1])
		sa(val, TRUE);
	while (val->size_b > 0)
		pa(val, TRUE);
	return (0);
}
