/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:27:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 11:25:28 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** STEP 02 Next functions
*/

void	step_02_apply_change(t_val *val, t_cs *cs, int *nb_top_nbr)
{
	while (val->b[0] != cs->value)
	{
		if (cs->rotation)
			rrb(val, TRUE);
		else
			rb(val, TRUE);
	}
	if (cs->min == cs->max)
	{
		pa(val, TRUE);
		++(nb_top_nbr[0]);
	}
	else if (cs->min_or_max)
	{
		pa(val, TRUE);
		++(nb_top_nbr[0]);
	}
	else
	{
		pa(val, TRUE);
		ra(val, TRUE);
	}
}

int		step_02_loop(t_val *val, int *nb_top_nbr)
{
	t_cs cs;

	cs.max = get_max_value(val->b, val->size_b);
	cs.min = get_min_value(val->b, val->size_b);
	cs.min_or_max = min_or_max_is_nearest(val->b, val->size_b);
	cs.value = cs.min_or_max ? cs.max : cs.min;
	cs.rotation = select_rotation(val->b, cs.value, val->size_b);
	step_02_apply_change(val, &cs, nb_top_nbr);
	return (0);
}

int		step_02_rotate_heap(t_val *val, int nb_top_nbr, int default_size)
{
	int i;

	i = 0;
	while (i < nb_top_nbr)
	{
		ra(val, TRUE);
		++i;
	}
	if (!heap_solved(val))
		return (0);
	i = 0;
	while (i < default_size)
	{
		pb(val, TRUE);
		++i;
	}
	if (heap_solved(val))
		step_02(val);
	else
		return (0);
	return (0);
}
